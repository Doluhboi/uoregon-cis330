// This program is from:Nicole Marsaglia 
// The author believes it has <2> memory errors

#include <iostream>
#include <stdlib.h>

using std::cout;

int main()
{
int * var;
var = new int[10];
var[0] = 0;
var[1] = 1;
var[2] = 2;
var[3] = 3;
var[4] = 4;
var[5] = 5;
var[6] = 6;
var[7] = 7;
var[8] = 8;
var[9] = 9;
cout << "Print 0-9: \n";
int i;
for (i = 0; i <= 10; i++)
	cout << var[i]<< " ";

cout << "\n";
delete [] var;

int *array = (int *) malloc(10);
array[0] = 0;
array[1] = 1;
array[2] = 2;
array[3] = 3;
array[4] = 4;
array[5] = 5;
array[6] = 6;
array[7] = 7;
array[8] = 8;
array[9] = 9;
cout << "Print 0-9: \n";
for (i = 0; i < 10; i++)
	cout << array[i]<< " ";
free(array);
cout << "\n";

}
