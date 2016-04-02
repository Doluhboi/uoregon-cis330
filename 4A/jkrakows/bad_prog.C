#include <stdio.h>
// This program is from: 
// The author believes it has <X> memory errors

int computePower(int input, int power){
	int i;
	int output = 1;
	for (i = 0; i < power; i++){
		output *= input;
	}
	return output;
}


int main(){
	int *x = new int[3*sizeof(int)];
	int *power = new int [3];
	x[0] = 4;
	x[1] = 5;
	x[2] = 6;

	power[0] = 3;
	power[1] = 4;
	power[2] = 5;
	power[3] = 6;
	power[4] = 2;

	delete [] x;
	delete [] power;

	int fourcube = computePower(x[0], power[0]);
	int fivecube = computePower(x[1], power[0]);
	int sixcube = computePower(x[2], power[0]);
	int fourfourth = computePower(x[0], power[1]);
	int sixsquare = computePower(x[2], power[4]);

	printf("4 Cubed :%d\n", fourcube);
	printf("5 Cubed :%d\n", fivecube);
	printf("6 Cubed :%d\n", sixcube);
	printf("6 Squared : %d\n", sixsquare);
}

