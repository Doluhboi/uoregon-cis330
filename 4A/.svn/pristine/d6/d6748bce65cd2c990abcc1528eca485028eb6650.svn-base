// This program is from: Sam Nelson
// The author believes it has <4> memory errors

#include <iostream>

int main()
{
	char *input[2] = {"hello", "world"};
	char *firstword= NULL;
	char *secondword= firstword;
	char *arraysize[2] = {firstword,secondword};
	for (int i = 0; i <= 6; ++i){
		std::cout<<input[i-1];
		if (input[i-1] != NULL)
			if (firstword == NULL)
				firstword = input[i];
			else if (secondword == NULL)
				secondword = input[i];
	std::cout<<firstword<<secondword;}
//expected output is "hihelloworld"

}
