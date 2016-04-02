/* filters.C 
Execute methods for filters */

#include <filters.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *Shrinker::FilterName() {
	return "Shrinker";
}
const char *LRConcat::FilterName() {
	return "LRConcat";
}
const char *TBConcat::FilterName() {
	return "TBConcat";
}
const char *Blender::FilterName() {
	return "Blender";
}

void Shrinker::Execute() {
	// output image is half width and height

	if(img1 == NULL) {
		char msg[1024];
		sprintf(msg, "%s: no input1!", SinkName());
		DataFlowException e(SinkName(), msg);
		throw e;
	}

	int width = img1->getWidth();
	int height = img1->getHeight();
	int halfWidth = width/2;
	int halfHeight = height/2;

	img.ResetSize(halfWidth, halfHeight);
    
	unsigned char * temp = (unsigned char *) malloc(halfWidth*halfHeight*3);
    
	for(int i=0; i<halfHeight; i++) {
		for(int j=0; j<halfWidth; j++) {
			int in = 3*(i*2*width+j*2);
			int out = 3*(i*halfWidth+j);
			temp[out] = img1->getData()[in];
			temp[out+1] = img1->getData()[in+1];
			temp[out+2] = img1->getData()[in+2];
		}
	}
    
	img.setData(temp);
	free(temp);
}

void LRConcat::Execute() {
	// take two input images that have the same height
	//	output single image combined left to right
    if(img1 == NULL) {
		char msg[1024];
		sprintf(msg, "%s: no input1!", SinkName());
		DataFlowException e(SinkName(), msg);
		throw e;
	}

	if(img2 == NULL) {
		char msg[1024];
		sprintf(msg, "%s: no input2!", SinkName());
		DataFlowException e(SinkName(), msg);
		throw e;
	}

	int width1 = img1->getWidth();
	int height1 = img1->getHeight();
	int width2 = img2->getWidth();
	int height2 = img2->getHeight();
	int outWidth = width1+width2;
	int outHeight = (height1+height2)/2;

   	if(height1 != height2) {
		char msg[1024];
		sprintf(msg, "%s: heights must match: %d, %d", SinkName(), height1, height2);
		DataFlowException e(SinkName(), msg);
		throw e;
	}

	img.ResetSize(outWidth, outHeight);
	
	unsigned char * tempLR = (unsigned char *) malloc(outWidth*outHeight*3);
    
	for(int i=0; i < width1; i++) {
		for(int j=0; j < outHeight; j++) {
			int out = (j*outWidth+i)*3;
			int in = (j*width1+i)*3;
			tempLR[out] = img1->getData()[in];
			tempLR[out + 1] = img1->getData()[in + 1];
			tempLR[out + 2] = img1->getData()[in + 2];
		}
	}
	
	for(int i=0; i < width2; i++) {
		for(int j=0; j < outHeight; j++) {
			int in2 = (j*width2+i)*3;
			int out = (j*outWidth+width1+i)*3;
			tempLR[out] = img2->getData()[in2];
			tempLR[out + 1] = img2->getData()[in2 + 1];
			tempLR[out + 2] = img2->getData()[in2 + 2];
		}
	}
    
	img.setData(tempLR);
	
	free(tempLR);
}

void TBConcat::Execute() {
	// take two input images that have same width
	// output single image combined top and bottom

    if(img1 == NULL) {
		char msg[1024];
		sprintf(msg, "%s: no input1!", SinkName());
		DataFlowException e(SinkName(), msg);
		throw e;
	}

	if(img2 == NULL) {
		char msg[1024];
		sprintf(msg, "%s: no input2!", SinkName());
		DataFlowException e(SinkName(), msg);
		throw e;
	}

	int width1 = img1->getWidth();
	int height1 = img1->getHeight();
	int width2 = img2->getWidth();
	int height2 = img2->getHeight();
	int outHeight = height1+height2;
	int outWidth = (width1+width2)/2;

    if(width1 != width2) {
		char msg[1024];
		sprintf(msg, "%s: widths must match: %d, %d", SinkName(), width1, width2);
		DataFlowException e(SinkName(), msg);
		throw e;
	}
   
	img.ResetSize(outWidth, outHeight);
	
	unsigned char * tempTB = (unsigned char *) malloc(outHeight*outWidth*3);
    
	for(int i=0; i < outWidth; i++) {
		for(int j=0; j < height1; j++) {
			int out = (j*outWidth+i)*3;
			int in = (j*width1+i)*3;
			tempTB[out] = img1->getData()[in];
			tempTB[out + 1] = img1->getData()[in + 1];
			tempTB[out + 2] = img1->getData()[in + 2];
		}
	}
	
	for(int i=0; i < outWidth; i++) {
		for(int j=0; j < height2; j++) {
			int in2 = (j*width2+i)*3;
			int out = ((j+height1)*outWidth+i)*3;
			tempTB[out] = img2->getData()[in2];
			tempTB[out + 1] = img2->getData()[in2 + 1];
			tempTB[out + 2] = img2->getData()[in2 + 2];
		}
	}
    
	img.setData(tempTB);
	free(tempTB);
}

void Blender::SetFactor(float f) { 
	factor = f; 
}

void Blender::Execute() {
	// take two input images with same width and height
	// blend together with factor
     if(img1 == NULL) {
		char msg[1024];
		sprintf(msg, "%s: no input1!", SinkName());
		DataFlowException e(SinkName(), msg);
		throw e;
	}

	if(img2 == NULL) {
		char msg[1024];
		sprintf(msg, "%s: no input2!", SinkName());
		DataFlowException e(SinkName(), msg);
		throw e;
	}

	int width1 = img1->getWidth();
	int height1 = img1->getHeight();
	int width2 = img2->getWidth();
	int height2 = img2->getHeight();
    
	int outHeight = (height1+height2)/2;
	int outWidth = (width1+width2)/2;

    if(height1 != height2 || width1 != width2) {
		char msg[1024];
		sprintf(msg, "%s: image size must match: %d x %d, %d x %d", SinkName(), width1, height1, width2, height2);
		DataFlowException e(SinkName(), msg);
		throw e;
	}

    if(factor > 1.0) {
		char msg[1024];
		sprintf(msg, "%s: Invalid factor for Blender: %f", SinkName(), factor);
		DataFlowException e(SinkName(), msg);
		throw e;
	}

	img.ResetSize(outWidth, outHeight);
    
	unsigned char * tempB = (unsigned char *) malloc(outHeight*outWidth*3);
    
	for(int i=0; i < outWidth; i++) {
		for(int j=0; j < outHeight; j++) {
			int index = (j*outWidth+i)*3;
			tempB[index] = img1->getData()[index]*factor + img2->getData()[index]*(1-factor);
			tempB[index + 1] = img1->getData()[index + 1]*factor + img2->getData()[index + 1]*(1-factor);
			tempB[index + 2] = img1->getData()[index + 2]*factor + img2->getData()[index + 2]*(1-factor);					}
	}
	
	img.setData(tempB);
	free(tempB);	
}



