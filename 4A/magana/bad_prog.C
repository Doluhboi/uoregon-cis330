// This program is from: Alex Magana 
// The author believes it has <2> memory errors
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
   for (int i = 0; i < 10; i++)
   {
	if (i % 2 == 0){
	    printf("The value of i is: %d\n", i);
	    printf("The value of i is even\n");
        }
	else{
	    printf("The value of i is: %d\n", i);
	    printf("The value of i is odd\n");
	}
   }

   int a;
   int b = a + 4;
   printf("The value of b is: %d\n", b);
   
   a = 2;
   int c = 3 * a;
   printf("The value of c is: %d\n", c);

   char *strptr = (char *) malloc(25);
   free(strptr);
   free(strptr);
   strcpy(strptr, "Copy successful!!!");
   printf("%s\n", strptr);

   b = 1;
   c = 1;

   for(int j = 0; j < 10; j++)
   {
	if(j % 3 == 1){
	   a *= j;
	   printf("The value of a is: %d\n", a);
	}
	else if (j % 3 == 1){
	   b *= j;
	   printf("The value of b is: %d\n", b);
	}
	else
	   printf("The value of c is: %d\n", j);
   }

   printf("THIS IS THE END OF MY PROGRAM!\n");

   return 0;
}
