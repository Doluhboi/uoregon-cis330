/* PNMreaderC.C 
reader execute method */

#include <PNMreaderC.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

PNMreaderC::PNMreaderC(char *f) {
	filename = (char *) malloc(strlen(f)+1);
	strcpy(filename, f);
}
PNMreaderC::~PNMreaderC() {
	free(filename);
}
 
/* reads in a .pnm image and stores it */
void PNMreaderC::Execute() {
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
