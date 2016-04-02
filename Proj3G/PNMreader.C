/* PNMreader.C
fstream reader execute method */

#include <PNMreader.h>
#include <stdlib.h>
#include <string.h>
#include <iostream> // std::cout
#include <fstream> // std::ifstream

using namespace std;

PNMreader::PNMreader(const char *f) {
	filename = (char *) malloc(strlen(f)+1);
	strcpy(filename, f);
}

PNMreader::~PNMreader() {
	free(filename);
}

const char *PNMreader::SourceName() {
	return "PNMreader";
}

/* reads in a .pnm image and stores it */
void PNMreader::Execute() {

    ifstream ifs;
	ifs.open(filename, ios::binary);

    char magicNum[128];
	int width, height, maxval;
	
	if(!ifs) {
		cerr <<  "Unable to open file " << filename << endl;
	}

	ifs >> magicNum >> width >> height >> maxval;
	ifs.get();

	img.ResetSize(width, height);

//	cout << magicNum << " " << width << " " << height << " " << maxval << endl;
 
	if(strcmp(magicNum, "P6") != 0) {
		cerr <<  "Unable to read from file " << filename << ", because it is not a PNM file of type P6" << endl;
	}
	
	unsigned char * temp = (unsigned char *) malloc(3*height*width);

	ifs.read((char *) temp, width*height*3); 
	img.setData((unsigned char *) temp);

	ifs.close();
	free(temp);
}

