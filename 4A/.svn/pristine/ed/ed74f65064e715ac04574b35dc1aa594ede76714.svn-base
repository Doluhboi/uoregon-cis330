// This program is from:Colter Therrell
// The author believes it has <5> memory errors

#include <stdio.h>

void foo()
{
	char *x = 0;
	*x = 37;
}

void foo2()
{
	int x;
	int arr[] = { 1, 3, 5, 7 };
	x = arr[4]; 
}

void foo3()
{
	char* x = "this is a string literal";
	x[4] = 'C';
}

class Object
{
	public:
		int adder(int x, int y)
		{
			return x + y;
		}
};

int main()
{
	foo();
	foo2();
	foo3();
	Object* object = new Object();
	delete object;
	object->adder(4, 5); 

	char *pointer = malloc(3);
	*pointer = 'x';

	*(pointer + 1) = 'y';

	*(pointer + 2) = 'z';

	free(pointer);

	*pointer = 'x';

	return 0;

}
