#ifndef SINK_H
#define SINK_H
#include <image.h>
#include <string.h>
#include <stdio.h>

class Sink {
	protected:
    	const Image *img1;
		const Image *img2;
	public:
		Sink() {
			img1 = NULL;
			img2 = NULL;
		}
    	void SetInput(const Image *img1);
   		void SetInput2(const Image *img2);
};

#endif
