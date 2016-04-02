// This program is from: Jason Kranz 
// The author believes it has <4> memory errors
#include <iostream>

int main()
{
    int num1,num2;
    
    int *arr = new int[6];
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 1;
    arr[3] = 2;
    arr[4] = 3;
    arr[5] = 5;

    for (int i = 0; i<6; i++)
    {
	std::cout << "Fibonacci Sequence ";
	std::cout << arr[i]+arr[i+1];
	std::cout << "\n";
	arr[i] = arr[i]+arr[i+1];
    }
    
    free(arr);
    std::cout << "New Array:" << "\n";

    for (int i = 0; i<6; i++)
    {
        std::cout << arr[i];
	std::cout << "\n";   
    }

    num1 = num2 + 1;
   
    std::cout << "num1 should be ";
    std::cout << 1;
    std::cout << "\n";
    
    num2 = num1 + 1;
    
    std::cout << "num2 should be ";
    std::cout << 2;
    std::cout << "\n";

    std::cout << "num1 is " << num1 << "\n"; 
    std::cout << "num2 is " << num2 << "\n"; 

    return 0;
}




