// This program is from: Doug Beick 
// The author believes it has <3> memory errors

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int w = 3;
    int h = 3;
    int d = 3;
    int *buffer = (int *)malloc(w*h*d);
    int **buffer2 = (int **)malloc(w*h*d);

    int count = 0;
    for(int i = 0; i < w; i++){
        for(int j = 0; i < h; j++){
            for(int k = 0; k < d; k++){
                buffer[i*h*d + j*d + k] = count;
                count++;
            }
        }
    }

    for(int n = 0; n < w*h*d; n++){
        buffer2[n] = &buffer[n];
    }

    free(buffer);

    for(int n = 0; n < w*h*d; n++){
        printf("%d\n", *buffer2[n]);
    }

    free(buffer2);
}
