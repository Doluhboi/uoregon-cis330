// This program is from: Megan McMillan 
// The author believes it has < 4 > memory errors
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

class Object {
	private:
		int x;
		char *data; 
	public:
		Object(int, char *);
		~Object();

		void resetX(int _x) { x = _x; }
		void resetData(char *d) { memcpy(data, d, x*sizeof(char *)); }
		int getX() { return x; }
		char* getData() { return data; }
};

Object::Object(int _x, char *d) {
	x = _x;
	memcpy(data, d, x*sizeof(char));
}

Object::~Object() { free(data); }

int main()
{
	int x = 3;
	char *buffer = (char *) malloc(x*sizeof(char *));
	buffer[0] = 'B';	
	buffer[1] = 'a';
	buffer[2] = 'd';
	Object obj(x, buffer);
	char *b = obj.getData();
	obj.resetData(b);
	free(buffer);
	free(b);
}
