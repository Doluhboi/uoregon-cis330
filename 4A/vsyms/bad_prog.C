// This program is from: Victoria Norton
// The author believes it has <2> memory errors

#include <stdio.h>
#include <iostream>

using std::cout;
using std::endl;

int GCD(int m, int n)
{
	if(n == 0)
	{
		return m;
	}
	else
	{
		return GCD(n, m%n);
	}
}

int extendGCD(int m, int n)
{
	int r, q, swap, swap2, swap3;
	int a = 0; 
	int b = 1;
	int a2 = 1;
	int b2 = 0;

	if (m < n)
	{
		swap = m;
		m = n;
		n = swap;
	}

	while(n != 0)
	{
		q = m/n;
		r = m%n;
		m = n;
		n = r;

		swap2 = a;
		a = a2 - q * a;
		a2 = swap2;

		swap3 = b;
		b = b2 - q * b;
		b2 = swap3;
	}

	cout << "a = " << a2 << endl;
	cout << "b = " << b2 << endl;
}

int main()
{
	const char *gcdStr = NULL;
	const char *extGCDStr = NULL;

	cout << "gcd = " << GCD(2015, 615) << endl;
	cout << extGCDStr << endl;
	extGCDStr = "a and b values: ";
	extendGCD(2015, 615);
	
	delete [] gcdStr;
	delete [] extGCDStr;
}