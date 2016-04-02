/* filters.C */

#include <filters.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Filter::Update() {
	if(img1 != NULL) 
		img1->Update();
        //fprintf(stderr, "in filter::update, img1->Update filters.C\n");
	if(img2 != NULL)
		img2->Update();
        //fprintf(stderr, "in filter::update, img2->Update filters.C\n");
    //fprintf(stderr, "in filter::update, calling execute filters.C\n");
	Execute();	
}

void Shrinker::Execute() {
	// output image is half width and height
    
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
    
	int width1 = img1->getWidth();
	int height1 = img1->getHeight();
	int width2 = img2->getWidth();
	int height2 = img2->getHeight();
	int outWidth = width1+width2;
	int outHeight = (height1+height2)/2;
    
	img.ResetSize(outWidth, outHeight);
	
	if (height1 != height2) {
		printf("Input images have different heights\n");
	}
    
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
    
	int width1 = img1->getWidth();
	int height1 = img1->getHeight();
	int width2 = img2->getWidth();
	int height2 = img2->getHeight();
	int outHeight = height1+height2;
	int outWidth = (width1+width2)/2;
    
	img.ResetSize(outWidth, outHeight);
	
	if (width1 != width2) {
		printf("Input images have different widths\n");
	}
	
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

void Blender::Execute() {
	// take two input images with same width and height
	// blend together with factor
    
	int width1 = img1->getWidth();
	int height1 = img1->getHeight();
	int width2 = img2->getWidth();
	int height2 = img2->getHeight();
    
	int outHeight = (height1+height2)/2;
	int outWidth = (width1+width2)/2;
    
	img.ResetSize(outWidth, outHeight);
    
	if (width1 != width2 && height1 != height2) {
		printf("Input images have different heights or widths\n");
	}
    
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



