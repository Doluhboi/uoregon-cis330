/* Megan McMillan Project 3A 5/3/14 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int height; 
	int width;
	int maxval;
	unsigned char *buffer;
	
} Image;


/* Take in a file and read image into buffer */

Image *
ReadImage(char *filename)
{
    FILE *f = fopen(filename, "rb");
    Image *img = NULL;
    char magicNum[128];
    int  width, height, maxval;
	
	if (f == NULL)
    {
        fprintf(stderr, "Unable to open file %s\n", filename);
        return NULL;
    }

    fscanf(f, "%s\n%d %d\n%d\n", magicNum, &width, &height, &maxval);
	
/*
    printf("Magic num = %s width = %d, height = %d, maxval = %d\n",
            magicNum, width, height, maxval);
 */

    if (strcmp(magicNum, "P6") != 0)
    {
        fprintf(stderr, "Unable to read from file %s, because it is not a PNM file of type P6\n", filename);
        return NULL;
    }
	
	img = malloc(sizeof(Image));	
	img->height = height;
	img->width = width;
	img->maxval = maxval;
	img->buffer = malloc(width*height*3*sizeof(unsigned char));

	fread(img->buffer, sizeof(unsigned char)*3, width*height, f);  

	fclose(f);
	return img;
}


void WriteImage(Image *img, char *filename)
{
	FILE *f = fopen(filename, "wb");
	fprintf(f, "%s\n%d %d\n%d\n","P6", img->width, img->height, img->maxval);
	fwrite(img->buffer, sizeof(unsigned char)*3, img->width*img->height, f);
	fclose(f);
}

					
Image *
YellowDiagonal(Image *input)
{
	Image *image = malloc(sizeof(Image));
	image->height = input->height;
	image->width = input->width;
	image->maxval = input->maxval;
	image->buffer = malloc(image->width*image->height*3*sizeof(unsigned char));

	memcpy(image->buffer, input->buffer, sizeof(unsigned char)*input->width*input->height*3);

	for(int i=0; i<image->width; i++) {
		if(i==image->height){
			break;
		}

		image->buffer[(i*3*image->width)+i*3+0] = 255;
		image->buffer[(i*3*image->width)+i*3+1] = 255;
		image->buffer[(i*3*image->width)+i*3+2] = 0;	
	}

	return image;
}

int main(int argc, char *argv[])
{
	if(argc != 3) {
		printf("Please give three arguments in the format: ./proj3 <input> <output>");
		exit(EXIT_FAILURE);
	}

	Image *image;
	image = ReadImage(argv[1]);
    Image *image1;
	image1 = YellowDiagonal(image);
	WriteImage(image1, argv[2]);
	free(image1->buffer);
	free(image1);
	free(image->buffer);
	free(image);	
}
