// This program is from: morgan(zhuojun)
// The author believes it has <1> memory errors

#include<iostream>
using namespace std;

class Pixel
{
    public:
        unsigned char* buf;
        Pixel(){buf = new unsigned char[3];}
        ~Pixel(){delete[] buf;}

};

void print(Pixel *pixels, int len)
{
    //cout<<"Printing..."<<endl;
    for(int i=0;i<len;i++)
    {
        cout<<(int)pixels[i].buf[0]<<"\t"<<(int)pixels[i].buf[1]<<"\t"<<(int)pixels[i].buf[2]<<endl;
    }
}
int main()
{
    Pixel pixels[3];
    Pixel tmp;
    for(int i=0;i<3;i++)
    {
        pixels[i].buf[0] = ((i+3)*100 + 0*10)%255;
        pixels[i].buf[1] = ((i+1)*100 + 1*10)%255;
        pixels[i].buf[2] = ((i+2)*100 + 2*10)%255;
    }

    cout<<"Before swap:"<<endl;
    print(pixels,3);

    //switching the 1st and the 3rd 
    tmp = pixels[0];
    pixels[0] = pixels[2];
    pixels[2] = tmp;

    cout<<"\nAfter swap:"<<endl;
    print(pixels,3);
}
