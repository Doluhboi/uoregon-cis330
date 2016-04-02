// This program is from: Tom Rowland
// The author believes it has <1> memory errors
#include <cstdio>

int
add(char *operand1, char *operand2, char **answer)
{
    int length1 = 0;
    int length2 = 0;
    while(*(operand1 + length1) != '\0') {
        length1++;
    }
    while(*(operand2 + length2) != '\0') {
        length2++;
    }

    int larger = length1 < length2 ? length2 : length1;
    int i;
    int tempInt1;
    int tempInt2;
    int value;
    int total;
    int remainder = 0;
    char *solution = new char[1024]();
    for (i = 0; i < larger; i++) {
        tempInt1 = *(operand1 + (length1 - (i + 1))) - 48;
        tempInt2 = *(operand2 + (length2 - (i + 1))) - 48;
        total = tempInt1 + tempInt2 + remainder;
        remainder = remainder + (total / 10);
        value = (total % 10) + 48;
        *(solution + i) = (total % 10) + 48;
    }

    int answerLength = 0;
    while (*(solution + answerLength) != '\0') {
        answerLength++;
    }
    char *answerTemp = new char[answerLength + 1]();
    
    for (int i = 0; i < answerLength; i++) {
        *(answerTemp + (answerLength - (i + 1))) = *(solution + i);
    }
    *answer = answerTemp;
    delete[] solution;

    return 0;
}

int
main(int argc, char *argv[])
{
    char *operand1 = "12345";
    char *operand2 = "46832798";
    char *answer;

    add(operand1, operand2, &answer);
    printf("This answer is incorrect, your task is to figure out why.\n");
    printf("%s + %s = %s\n", operand1, operand2, answer);
    delete[] answer;
    return 0;
}
