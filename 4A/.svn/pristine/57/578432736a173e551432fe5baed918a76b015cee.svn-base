// This program is from: Jimmy Wong 
// The author believes it has <3> memory errors

#include <iostream>

using std::cerr;
using std::cout;
using std::cin;
using std::endl;

int isEven(int array[]) {
	int *buffer = new int[3];
	delete[] buffer;
	for(int i = 1; i <= 3; ++i) {
		if(array[i] % 2 == 0) {
			cerr << array[i] << " is even" << endl;
		}
		else {
			cerr << array[i] << " is odd" << endl;
			delete[] buffer;
			return false;
		}
	}
	delete[] buffer;
	return true;
}

int main() {

	int x, y, z;
	cout <<"Type 3 even integers" << endl;
	cin >> x >> y >> z;

	int arr[3] = {x, y, z};

	bool allEven = isEven(arr);

	if(allEven == true) {
		cout <<"All entered integers are even" << endl;
	}

	else {
		cout <<"You entered at least 1 odd integer" << endl;
	}

	delete(arr);
}
