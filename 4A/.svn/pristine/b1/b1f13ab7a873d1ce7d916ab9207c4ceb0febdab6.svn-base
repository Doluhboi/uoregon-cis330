// This program is from: Erik Steringer
// The author believes it has <1> memory errors

class A
{
public:
	A();
	~A();
	int *x;
	void DoThing(int, int);
};

A::A()
{
	x = new int[64];
}

A::~A()
{
	delete [] x;
}

// assigns a given number to a given index
void A::DoThing(int index, int number)
{
	x[index] = number;
}

int main()
{
	A obj;
	obj.DoThing(0, 0);
	obj.DoThing(1, 1);
	obj.DoThing(2, 1);
	obj.DoThing(3, 2);
	obj.DoThing(4, 3);
	obj.DoThing(5, 5);
	obj.DoThing(6, 8);
	obj.DoThing(7, 13);
	obj.DoThing(8, 21);
	obj.DoThing(9, 34);
	obj.DoThing(10, 55);
	obj.DoThing(11, 89);
	obj.DoThing(12, 144);
	obj.DoThing(13, 233);
	obj.DoThing(14, 377);
	obj.DoThing(0xF, 0xFF);
	delete [] obj.x;
}
