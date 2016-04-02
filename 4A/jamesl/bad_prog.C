// This program is from: James Lee 
// The author believes it has <5> memory errors
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int arr = new int[100];
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			int index = i * 10 + j; 
			arr[index] = index + 1;
			printf("%d\n", arr[index]);
		}
	}

	int arr2 = new int[100];
	for (int k = 0; k < 10; k++){
		for (int l = 0; l < 10; l++){
			int index2 =  k * 10 + l;
			arr2[index2] = arr[100 - index2];
			printf("%d\n", arr[index2]);
		}
	}
	free(arr2);
	free(arr2);

	int *arr3 = new int[100];
	for (int m = 0; m < 10; m++){
		for (int n = 0; n < 10; n++){
			int index3 = m * 11 + n;
			arr3[index3] = m * n;
			printf("%d\n", arr3[index3]);
		}
	}
	delete arr3;
}

