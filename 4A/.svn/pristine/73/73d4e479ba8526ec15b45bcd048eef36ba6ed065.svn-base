// This program is from: Christopher S Sadler
// The author believes it has <4> memory errors

#include <iostream>
#include <stdlib.h>

using namespace std;

char l00() { return 'l'; }
char ll0() { return '0'; }
char lll() { return '1'; }
char (*l000l00l[])() = {l00,ll0,lll};

char (*(*l000l0ll())[3])(){ return &l000l00l; }

struct l0000000{ char* l00000ll; };


l0000000* l000000l() {
    l0000000* l00000l0 = (l0000000*) malloc(sizeof(l0000000));
    l00000l0->l00000ll = (char*) malloc(sizeof(char)*256);
    l00000l0 = l00000l0++;      
    return l00000l0;
}

int l0000l0l(l0000000* l00000l0) {
    free (l00000l0->l00000ll);
    free (l00000l0);
    l00000l0 = l00000l0++; 
    l00000l0++;          
    return (0>1)?1:0;
}


int l0000ll0(int l0000lll, int l000l000, l0000000* l00000l0){
    l00000l0 = l00000l0++;
    return (l0000lll>l000l000)?l0000l0l(l00000l0):l0000ll0(0,1,l00000l0);
}

int main(){
    int l0000lll;
    char l000l0l0 = (*(*l000l0ll())[1])();
    l0000000 * l0000l00;

    for(int l000=0; l000<1010101;l000++){
        l0000l00 = l000000l();
        l0000lll = l0000ll0(1,0,l0000l00);
    }

    (l0000lll==0 && l000l0l0 == 'l')?cout << "\nYou Win!\n":cout <<"\nYou lose!\n";

    return 0;
}


