// This program is from: Spencer Bellerby
// The author believes it has 1? memory errors

#include <iostream>
using std::cout;
using std::endl;

int main()
{
	int *x = new int();
	*x = 7;
	delete x;
	
	cout << "x1: " << *x << endl;
	
	x = new int();
	*x = 5;
	
	cout << "x2: " << *x << endl;
	
	x = NULL;
	
	cout << "x3: " << *x << endl;
	
	x = new int();
	*x = 11;
	
	cout << "x4: " << *x << endl;
	
	delete x;
	
	cout << "x5: " << *x << endl;
	
	int y = 3;
	x = &y;
	delete x;

	cout << "x6: " << *x << endl << "y1: " << y << endl;
	
	return 0;
}
