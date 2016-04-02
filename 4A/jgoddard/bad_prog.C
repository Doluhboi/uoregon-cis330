#include <stdio.h>
#include <iostream>

// This program is from: 
// The author believes it has <2> memory errors

using namespace std;

class Line 
{
private:
	int length;
public:
	void setLength(int);
	int getLength();
};

void Line::setLength(int l)
{
	this->length = l;
}

int Line::getLength()
{
	return length;
}

int main()
{
	Line line;
	line.setLength(5);
	free(&line);
	int length = line.getLength();
	malloc(sizeof(line));
	cout << printf("length is %d\n", length);
	return 0;
}
