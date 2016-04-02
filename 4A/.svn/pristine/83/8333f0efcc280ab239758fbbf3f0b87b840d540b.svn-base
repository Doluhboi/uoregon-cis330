// This program is from: Kirsten Dawes  
// The author believes it has  3 or 4 memory errors
// matrix mulitplcation?
// transformation of vectors
//cat *.[Ch]|wc shows how many long line are in a file.
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
class Datamemb{
	int* data;
	public:
		void setBuffer(int *data);
		int * getBuffer();
};
void Datamemb:: setBuffer(int *data){
		
	this ->data = data;};
int *Datamemb:: getBuffer(){
	return data;};
int main(){
	
	int * datame;
	Datamemb Data;
	Data.setBuffer(datame);
	int i = 0;
	for( i ;i<15; i++){
		fprintf(stderr, "Data : at i = %d, %d\n", i , Data.getBuffer()[i]);
		}
	free(datame);
	int array[9];

	for (i; i<9; i++){
		array[i]= i+2;
		}

	for (i; i< 15; i++){
		datame[i] = array[i];
	}
	Data.setBuffer(datame);
};
