/* filters.h 
Shrinker, LRConcat, TBConcat, Blender classes that inherit from filter */

#ifndef FILTERS_H
#define FILTERS_H
#include <filter.h>

class Shrinker : public Filter {
	public:
    	virtual void Execute();
		virtual const char *FilterName();
};

class LRConcat : public Filter {
	public:
    	virtual void Execute();
		virtual const char *FilterName();
};

class TBConcat : public Filter {
	public:
    	virtual void Execute();
		virtual const char *FilterName();
};

class Blender : public Filter {
	protected:
    	float factor;
	public:
    	void SetFactor(float f);
    	virtual void Execute();
		virtual const char *FilterName();
};

#endif
