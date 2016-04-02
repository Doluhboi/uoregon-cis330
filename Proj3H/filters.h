/* filters.h 
Shrinker, LRConcat, TBConcat, Blender classes that inherit from filter */

#ifndef FILTERS_H
#define FILTERS_H
#include <filter.h>

class CheckSum : public Sink {
	public:
		void OutputCheckSum(char *filename);
		const char *SinkName() { return "CheckSum"; }
};

class Color : public Source {
    protected:
        int width, height;
        unsigned char red, green, blue;
    
    public:
        Color(int _w, int _h, unsigned char r, unsigned char g, unsigned char b);
        ~Color();
        virtual void Execute();
        virtual const char *SourceName() { return "Color"; }
};

class Invert : public Filter {
	public:
    	virtual void Execute();
        virtual const char *FilterName() { return "Invert"; }
};

class Transpose : public Filter {
	public:
    	virtual void Execute();
        virtual const char *FilterName() { return "Transpose"; }
};

class Crop : public Filter {
    public:
        Crop()  { Istart = Istop = Jstart = Jstop = -1; };
        virtual const char *FilterName() { return "Crop"; };
        virtual void   Execute();
        void           SetRegion(int Istart_, int Istop_, int Jstart_, int Jstop_)
        {
            Istart = Istart_;
            Istop  = Istop_;
            Jstart = Jstart_;
            Jstop  = Jstop_;
        }
    
    private:
        int Istart, Istop, Jstart, Jstop;
};

class Shrinker : public Filter {
	public:
    	virtual void Execute();
        virtual const char *FilterName() { return "Shrinker"; }
};

class LRConcat : public Filter {
	public:
    	virtual void Execute();
        virtual const char *FilterName() { return "LRConcat"; }
};

class TBConcat : public Filter {
	public:
    	virtual void Execute();
        virtual const char *FilterName() { return "TBConcat"; }
};

class Blender : public Filter {
	protected:
    	float factor;
	public:
    	void SetFactor(float f);
    	virtual void Execute();
		virtual const char *FilterName() { return "Blender"; }
};

#endif
