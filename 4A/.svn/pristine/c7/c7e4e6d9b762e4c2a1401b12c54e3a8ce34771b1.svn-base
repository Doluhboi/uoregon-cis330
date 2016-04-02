// This program is from Kat Pinto: 
// The author believes it has 2? memory errors

#include <stdio.h> 
#include <string.h>
#include <iostream>

using namespace std;

int Count(int x) {
	x++;
	return x;
}

int ResetCount(int x) {
	int *var = NULL;
	x = *var;
	return x;
}

int main() {
	int x = 0;
	string *ghosts = new string[4];
	ghosts[0] = "blinky";
	ghosts[1] = "pinky";
	ghosts[2] = "clyde";
	ghosts[3] = "inky"; 
	for (int i = 0; i < 4; ++i) {
		cout << "PACMAN has consumed " << ghosts[i] << "\n";
		cout << "Ghosts Consumed: " << Count(x) << "\n";
		x = Count(x);
		if (x == 4) {
			cout << "Resetting Ghosts" << "\n";
			ResetCount(x);
			cout << "Ghost count reset" << "\n";
			i = -1;
			x = 0;
		}
	}
}
