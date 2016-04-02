#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

void  ReadImage(char *filename, Image &img) {
	FILE *f = fopen(filename, "rb");
	char magicNum[128];
	int width, height, maxval;
	
	if(f == NULL) {
		fprintf(stderr, "Unable to open file %s\n", filename);
	}

	fscanf(f, "%s\n%d %d\n%d\n", magicNum, &width, &height, &maxval);

//	printf("Magic num = %s width = %d, height = %d, maxval = %d\n", magicNum, width, height, maxval);

	if(strcmp(magicNum, "P6") != 0) {
		fprintf(stderr, "Unable to read from file %s, because it is not a PNM file of type P6\n", filename);
	}
	
	unsigned char * temp = (unsigned char *) malloc(sizeof(unsigned char)*3*height*width);
	fread(temp, sizeof(unsigned char)*3, width*height, f);
	img.ResetSize(width, height);
	img.setData(temp);
	fclose(f);
	free(temp);
}

void WriteImage(char *filename, Image &img) {
	FILE *f = fopen(filename, "wb");
	fprintf(f, "%s\n%d %d\n%d\n", "P6", img.getWidth(), img.getHeight(), 255);
	fwrite(img.getData(), sizeof(unsigned char)*3, img.getWidth()*img.getHeight(), f);
	fclose(f);
}

void HalveInSize(Image &input, Image &output) {
	// output image is half width and height 

	int width = input.getWidth();
	int height = input.getHeight();
	int halfWidth = width/2;
	int halfHeight = height/2;
	output.ResetSize(halfWidth, halfHeight);

	unsigned char * temp = (unsigned char *) malloc(halfWidth*halfHeight*3); 

	for(int i=0; i<halfHeight; i++) {
		for(int j=0; j<halfWidth; j++) {
			int in = 3*(i*2*width+j*2);
			int out = 3*(i*halfWidth+j);
			temp[out] = input.getData()[in];
			temp[out+1] = input.getData()[in+1];
			temp[out+2] = input.getData()[in+2]; 	
		}	
	}

	output.setData(temp);
	free(temp);
}

void LeftRightConcatenate(Image &leftInput, Image &rightInput, Image &output) {
	// take two input images that have the same height 
	//	output single image combined left to right 

	int width1 = leftInput.getWidth();	
	int height1 = leftInput.getHeight();
	int width2 = rightInput.getWidth();
	int height2 = rightInput.getHeight();
	int outWidth = width1+width2;
	int outHeight = (height1+height2)/2;

	output.ResetSize(outWidth, outHeight);
	
	if (height1 != height2) {
		printf("Input images have different heights\n");
	}

	unsigned char * tempLR = (unsigned char *) malloc(outWidth*outHeight*3);

	for(int i=0; i < width1; i++) {	
		for(int j=0; j < outHeight; j++) {
			int out = (j*outWidth+i)*3; 	
			int in = (j*width1+i)*3;
			tempLR[out] = leftInput.getData()[in];				
			tempLR[out + 1] = leftInput.getData()[in + 1];				
			tempLR[out + 2] = leftInput.getData()[in + 2];				
		}
	}
	
	for(int i=0; i < width2; i++) {
		for(int j=0; j < outHeight; j++) {
			int in2 = (j*width2+i)*3;
			int out = (j*outWidth+width1+i)*3;	
			tempLR[out] = rightInput.getData()[in2];				
			tempLR[out + 1] = rightInput.getData()[in2 + 1];				
			tempLR[out + 2] = rightInput.getData()[in2 + 2];		
		}
	}
		
	output.setData(tempLR);
	
	free(tempLR);
}

void TopBottomConcatenate(Image &topInput, Image &bottomInput, Image &output) {
	// take two input images that have same width 
	// output single image combined top and bottom

	int width1 = topInput.getWidth();	
	int height1 = topInput.getHeight();
	int width2 = bottomInput.getWidth();
	int height2 = bottomInput.getHeight();
	int outHeight = height1+height2;
	int outWidth = (width1+width2)/2;

	output.ResetSize(outWidth, outHeight);
	
	if (width1 != width2) {
		printf("Input images have different widths\n");
	}
	
	unsigned char * tempTB = (unsigned char *) malloc(outHeight*outWidth*3);

	for(int i=0; i < outWidth; i++) {	
		for(int j=0; j < height1; j++) {
			int out = (j*outWidth+i)*3; 	
			int in = (j*width1+i)*3;
			tempTB[out] = topInput.getData()[in];				
			tempTB[out + 1] = topInput.getData()[in + 1];				
			tempTB[out + 2] = topInput.getData()[in + 2];				
		}
	}
	
	for(int i=0; i < outWidth; i++) {
		for(int j=0; j < height2; j++) {
			int in2 = (j*width2+i)*3;
			int out = ((j+height1)*outWidth+i)*3;	
			tempTB[out] = bottomInput.getData()[in2];				
			tempTB[out + 1] = bottomInput.getData()[in2 + 1];				
			tempTB[out + 2] = bottomInput.getData()[in2 + 2];		
		}
	}

	output.setData(tempTB);	
	free(tempTB);
}

void Blend(Image &input1, Image &input2, float f, Image &output) {
	// take two input images with same width and height
	// blend together with factor 

	int width1 = input1.getWidth();	
	int height1 = input1.getHeight();
	int width2 = input2.getWidth();
	int height2 = input2.getHeight();

	int outHeight = (height1+height2)/2;
	int outWidth = (width1+width2)/2;
	float factor = f;	

	output.ResetSize(outWidth, outHeight);

	if (width1 != width2 && height1 != height2) {
		printf("Input images have different heights or widths\n");
	}

	unsigned char * tempB = (unsigned char *) malloc(outHeight*outWidth*3);

	for(int i=0; i < outWidth; i++) {	
		for(int j=0; j < outHeight; j++) {
			int index = (j*outWidth+i)*3; 
			tempB[index] = input1.getData()[index]*factor + input2.getData()[index]*(1-factor);				
			tempB[index + 1] = input1.getData()[index + 1]*factor + input2.getData()[index]*(1-factor);	
			tempB[index + 2] = input1.getData()[index + 2]*factor + input2.getData()[index]*(1-factor);					}
	}
	
	output.setData(tempB);
	free(tempB);	
}
