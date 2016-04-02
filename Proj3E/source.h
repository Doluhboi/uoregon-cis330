/* source.h */

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
		Source() {
			img.setSource(this);
		}	
		Image * GetOutput(void);
		virtual void Update();
};

#endif
