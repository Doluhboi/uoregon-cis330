/* PNMwriterC.C 
write method for writer class */
#include <PNMwriterC.h>
#include <stdio.h>

/* writes the image data to a .pnm file */
void PNMwriterC::Write(char *filename) {
	FILE *f = fopen(filename, "wb");
	fprintf(f, "%s\n%d %d\n%d\n", "P6", img1->getWidth(), img1->getHeight(), 255);
	fwrite(img1->getData(), sizeof(unsigned char)*3, img1->getWidth()*img1->getHeight(), f);
	fclose(f);
}
