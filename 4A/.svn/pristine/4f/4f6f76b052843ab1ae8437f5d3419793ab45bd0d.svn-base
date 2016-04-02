// This program is from: Noah Daniels 
// The author believes it has <5> memory errors
#include <stdlib.h>
int main()
{
	int *charStr1;
	charStr1 = new int[12];
	int i;
	for (i = 0; i < 3213; i++)
	{
		charStr1[i] = i;
	}
	float *arr1;
	arr1 = (float *) malloc(sizeof(float) * 42);
	free(arr1);
	float f = arr1[2];
	free(arr1);
	double d1;
	double d2;
	d2 = d1;
	char *arr2;
	arr2 = (char *) malloc(sizeof(char) * 30);
	char c;
	c = arr2[0];
	return 0;
}
