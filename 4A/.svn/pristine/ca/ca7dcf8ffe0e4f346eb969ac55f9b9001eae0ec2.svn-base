#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This program is from: Muhammed Maurice 
// The author believes it has 3 memory errors

int main()
{	
	int arr[50];
	int *arr2 = new int[10];
	for (int i=0;i<=50;i++)
	{
		arr[i] = i;	
	}
	int max = 50;
	for (int j=0;j<=50;j++)
	{
		if (j<=max)
		{
			arr[j] = arr[max];
			
		}
			
		max = max -1;
	}
	for (int x=0;x<=50;x++)
	{
		printf("%d\n",arr[x]);
	}
	int a1 = arr2[4];
	
	for (int z=0;z<=10;z++)
	{
		arr2[z] = arr[z];
	}
	delete[] arr2;
	arr2[3] = arr2[6];
	free(arr);
	

}
