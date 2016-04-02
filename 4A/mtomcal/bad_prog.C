// This program is from: Michael Tomcal
// The author believes it has 1 memory errors

#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

int numOfFriend = 130;

class MichaelsLife {
    public:
        MichaelsLife();
        ~MichaelsLife();
        char **friends;
        int numOfFriends;
        void printFriends();
};

MichaelsLife::MichaelsLife() {
    int i;
    this->numOfFriends = 128;
    this->friends = new char*[this->numOfFriends];
    for (i = 0; i < numOfFriend; i++) {
        this->friends[i] = new char[128];
        strcpy(this->friends[i], "Jordan");
    }
}

void MichaelsLife::printFriends() {
    int i;
    for (i = 0; i < this->numOfFriends; i++) {
        cout << this->friends[i] << endl;
    }
}

MichaelsLife::~MichaelsLife() {
    delete [] this->friends;
}


int main()
{
    MichaelsLife mike;
    mike.printFriends();
}
