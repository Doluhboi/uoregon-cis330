// This program is from: Samuel Mintzmyer
// The author believes it has <1> memory errors

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


class Image
{
	public: 

	int width;
	int height;
	unsigned char * buffer;

	Image(int w, int h)
	{
		width = w;
		height = h;
		buffer = new unsigned char[width*height];
	}

	~Image()
	{
		width = NULL;
		height = NULL;
		delete[] buffer;
		buffer = NULL;
	}	
};

class LolCat : public Image
{
	public:

	 char * caption;
	
	LolCat(int w, int h, char * cat) : Image(w, h)
	{
		caption = new char[100];
		*caption = *cat;
	}

	~LolCat()
	{
		delete[] caption;
	}
};

int main()
{
	char * cattycaption = "If not for sits, why is it made of warm?";
	
	LolCat *cheezburger = new LolCat(100, 100, cattycaption);
	
	printf("Size of cheezburger is %d by %d\n", cheezburger->width, cheezburger->height);

	Image *meme = cheezburger;
	
	printf("Size of meme is %d by %d\n", meme->width, meme->height);

	delete meme;
	
	return 0;
}
