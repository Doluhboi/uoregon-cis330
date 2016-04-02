/* PNMwriter.C 
write method for writer class */

#include <PNMwriter.h>
#include <iostream>
#include <fstream>

using namespace std;

/* writes the image data to a .pnm file using fstream */
void PNMwriter::Write(const char *filename) {
	int w = img1->getWidth();
	int h = img1->getHeight();
	ofstream ofs;

	ofs.open(filename, ios::binary);

	ofs << "P6" << endl;
	ofs << w << " " << h << endl;
	ofs << 255 << endl;

	ofs.write((char *) img1->getData(), w*h*3);

	ofs.close();
}


