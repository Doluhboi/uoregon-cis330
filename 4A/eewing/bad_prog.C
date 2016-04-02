#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <ctime>
// This program is from: Elliott Ewing
// The author believes it has <4-5 (depending on definition of memory error)> memory errors

using std::cout;
using std::endl;

class memory {
    time_t a;
    int b;
    char *buffer;
    
    public:
    memory();
    virtual ~memory();
    int getA();
    int getB();
    char *getBuffer();
};

void allocate(int *ptr) {
    ptr = new int[10];

    int i;
    for(i=0; i<10; i++) {
        ptr[i] = i;
    }
}

int * getInt() {
    static int l = 0;
    l++;
    int k = l;
    return &k;
}

int main() {
    int *ptr;

    allocate(ptr);
 
    int i;
    for(i=0; i<10; i++) {
        cout << ptr[i] << endl;
    }
    memory mem;

    int *j = new int;
    j = getInt();
    cout << *j << "\n";
    j = getInt();
    cout << *j << "\n";
    j = getInt();
    cout << *j << "\n";
    j = getInt();
    cout << *j << "\n";
    j = getInt();
    cout << *j << "\n";
    cout << mem.getBuffer()[0] << "\n";
}

memory::memory() {
    time(&a);
    b = 2;
}
memory::~memory() {
    if(buffer != NULL) {
        delete [] buffer;
    }
}
int memory::getA() { return a; };
int memory::getB() { return b; };
char * memory::getBuffer() { return buffer; };
