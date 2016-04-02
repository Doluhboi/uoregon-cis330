// This program is from: Chase Kelly-Reif 
// The author believes it has 4 memory errors

#include <stdio.h>

int *count_3 = NULL;
int *count_5 = NULL;
int *count_7 = NULL;
int *count_9 = NULL;
int *count_11 = NULL;

int main()
{
	int i;
	for (i = 0; i <= 10000; i++)
	{
		if ((i % 3) == 0)
		{
			printf("divisible by 3\n");
			*count_3++;
		}

		if ((i % 5) == 0)
		{
			printf("divisible by 5\n");
			*count_5++;
		}

		if ((i % 7) == 0)
		{
			printf("divisible by 7\n");
			count_7++;
		}

		if ((i % 9) == 0)
		{
			printf("divisible by 9\n");
			*count_9++;
		}

		if ((i % 11) == 0)
		{
			printf("divisible by 11\n");
			*count_11++;
		}		
	}

	printf("Number of 3s: %d\n", *count_3);
	printf("Number of 5s: %d\n", count_5);
	printf("Number of 7s: %d\n", count_7);
	printf("Number of 9s: %d\n", count_9);
	printf("Number of 11s: %d\n", count_11);

	return 0;
}