/* source.h 
Source class*/

#ifndef SOURCE_H
#define SOURCE_H
#include <image.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

class Source {
	protected:
    	Image img;
    	virtual void Execute() = 0;
	public:
		Source();
		~Source();
		Image * GetOutput(void);
		virtual void Update();
		virtual const char *SourceName() = 0;
};

#endif
