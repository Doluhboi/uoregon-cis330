/* sink.h 
Sink class */

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
		Sink();
		~Sink();
    	void SetInput(const Image *img1);
   		void SetInput2(const Image *img2);
		virtual const char *SinkName() = 0;
};

#endif
