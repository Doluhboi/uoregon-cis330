/* filters.C 
Execute methods for filters */

#include <filters.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>


using namespace std;

void CheckSum::OutputCheckSum(char *filename) {
	// sums the total value in each rgb channel and outputs to file 

	if(img1 == NULL) {
		char msg[1024];
		sprintf(msg, "%s: no input1!", SinkName());
		DataFlowException e(SinkName(), msg);
		throw e;
	}

	int width = img1->getWidth();
	int height = img1->getHeight();
	int red = 0; 
	int green = 0; 
	int blue = 0;

	ofstream f;
	
	f.open(filename, ios::out);

	for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            int index = 3*(i*width + j);
            red += img1->getData()[index];
            green += img1->getData()[index+1];
            blue += img1->getData()[index+2];
		
			red %= 256;
			green %= 256;
			blue %= 256;
        }
    } 

	f << "CHECKSUM: " << red << ", " << green << ", " << blue << endl;
	f.close();
}

Color::Color(int _w, int _h, unsigned char r, unsigned char g, unsigned char b) {
    width = _w;
    height = _h;
    red = r;
    green = g;
    blue = b;
	
	img.ResetSize(width, height);
}

Color::~Color() {}

void Color::Execute() {
	// creates a solid color image of size width*height

	unsigned char * temp = (unsigned char *) malloc(width*height*3);

    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            int index = 3*(i*width + j);
            temp[index] = red;
            temp[index+1] = green;
            temp[index+2] = blue;
        }
    } 
	
	img.setData(temp);
	free(temp);
}

void Invert::Execute() {
	// inverts the colors in an image

	if(img1 == NULL) {
		char msg[1024];
		sprintf(msg, "%s: no input1!", SinkName());
		DataFlowException e(SinkName(), msg);
		throw e;
	}

	int width = img1->getWidth();
	int height = img1->getHeight();

	img.ResetSize(width, height);
    
	unsigned char * temp = (unsigned char *) malloc(width*height*3);
    
	for(int i=0; i<height; i++) {
		for(int j=0; j<width; j++) {
			int in = 3*(i*width+j);
			int out = 3*(i*width+j);
			temp[out] = 255 - img1->getData()[in];
			temp[out+1] = 255 - img1->getData()[in+1];
			temp[out+2] = 255 - img1->getData()[in+2];
		}
	}
    
	img.setData(temp);
	free(temp);
}


void Transpose::Execute() {
	// Transposes an image

	if(img1 == NULL) {
		char msg[1024];
		sprintf(msg, "%s: no input1!", SinkName());
		DataFlowException e(SinkName(), msg);
		throw e;
	}

	int width = img1->getWidth();
	int height = img1->getHeight();
	int newWidth = height;
	int newHeight = width;

	img.ResetSize(newWidth, newHeight);
    
	unsigned char * temp = (unsigned char *) malloc(newWidth*newHeight*3);
    
	for(int i=0; i<newHeight; i++) {
		for(int j=0; j<newWidth; j++) {
			int in = 3*(j*width+i);
			int out = 3*(i*newWidth+j);
			temp[out] = img1->getData()[in];
			temp[out+1] = img1->getData()[in+1];
			temp[out+2] = img1->getData()[in+2];
		}
	}
    
	img.setData(temp);
	free(temp);
}


void Crop::Execute(void) {
    if(img1 == NULL) {
		char msg[1024];
		sprintf(msg, "%s: no input1!", SinkName());
		DataFlowException e(SinkName(), msg);
		throw e;
	}
    if (Istart < 0 || Istop < 0 || Jstart < 0 || Jstop < 0) {
        char msg[1024];
        sprintf(msg, "%s: uninitialized region", FilterName());
        DataFlowException e(FilterName(), msg);
        throw e;
    }
    if (Istart >= img1->getWidth() || Istop >= img1->getWidth()) {
        char msg[1024];
        sprintf(msg, "%s: region outside image width", FilterName());
        DataFlowException e(FilterName(), msg);
        throw e;
    }
    if (Jstart >= img1->getHeight() || Jstop >= img1->getHeight()) {
        char msg[1024];
        sprintf(msg, "%s: region outside image height", FilterName());
        DataFlowException e(FilterName(), msg);
        throw e;
    }
    if (Istop < Istart || Jstop < Jstart) {
        char msg[1024];
        sprintf(msg, "%s: invalid region", FilterName());
        DataFlowException e(FilterName(), msg);
        throw e;
    }
    
    int height = Jstop-Jstart+1;
    int width  = Istop-Istart+1;
    int inputWidth = img1->getWidth();
    img.ResetSize(width, height);
    
    unsigned char * temp = (unsigned char *) malloc(width*height*3);
    
    for (int i = Istart ; i <= Istop ; i++)
        for (int j = Jstart ; j <= Jstop ; j++)
        {
            int idx1 = j*inputWidth+i;
            int idx  = (j-Jstart)*width+(i-Istart);
            temp[3*idx]   = img1->getData()[3*idx1];
            temp[3*idx+1] = img1->getData()[3*idx1+1];
            temp[3*idx+2] = img1->getData()[3*idx1+2];
        }
    
    img.setData(temp);
	free(temp);
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



