#ifndef SOURCE_H
#define SOURCE_H
#include <image.h>
#include <stdlib.h>
#include <string.h>

class Source {
	protected:
		Image  img;
	public:
		virtual void Execute() = 0;
		Image * GetOutput();
};

#endif
