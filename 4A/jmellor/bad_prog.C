// This program is from: Josh Mellor
// The author believes it has <2> memory errors
#include <iostream>

using namespace std;

void makeBuffer(int * buf, int num);

int main(){
    int * buffer = NULL;
    int num = 51;

    makeBuffer(buffer, num);

    cout << "Times table for 2 up to 2*"<< num-1 << "." << endl;
    for(int i = 0; i < 2*num; i++){
        if(i % 2 == 0){
            cout << "2*" << buffer[i] << " = ";
        }else{
            cout << buffer[i] << endl;
        }
    }
    cout << endl;
    return 0;
}

void makeBuffer(int * buf, int num){
    bool times2 = false;
    int j = 0;

    for(int i = 0; i < num; i++){
        if(!times2){
            buf[i] = j;
            times2 = true;
            j--;
        }else{
            buf[i] = 2*j;
            times2 = false;
        }
        j++;
    }
}
