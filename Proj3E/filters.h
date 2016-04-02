/* filters.h */

#ifndef FILTERS_H
#define FILTERS_H
#include <source.h>
#include <sink.h>
#include <image.h>

class Filter : public Source, public Sink {
	public:
		virtual void Update();
};

class Shrinker : public Filter {
	public:
    	virtual void Execute();
};

class LRConcat : public Filter {
	public:
    	virtual void Execute();
};

class TBConcat : public Filter {
	public:
    	virtual void Execute();
};

class Blender : public Filter {
	protected:
    	float factor;
	public:
    	void SetFactor(float f) { factor = f; }
    	virtual void Execute();
};

#endif
