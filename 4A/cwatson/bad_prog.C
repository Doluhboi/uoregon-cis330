// This program is from: Cole Watson
// I blieve there are 2  memory errors 
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int * i = new int[3];
    int *j =(int*) malloc(sizeof(int) * 3);
    i[0] = 1;
    i[1] = 2;
    i[2] = 3;
    j[0] = 4;
    j[1] = 5;
    j[2] = 6;
    int p;
    int k;
    for (p = 0; p < 3; p ++){
        printf("%d\n", i[p]);
    }
    for(k = 0; k < 3; k ++){
        printf("%d\n", j[k]);
    }
    free(i);
    delete [] j;
    j[0] = 7;
    j[1] = 8;
    j[2] = 9;
    for(p = 0; p < 3; p++){
        printf("%d\n",j[p]);
    }
}
