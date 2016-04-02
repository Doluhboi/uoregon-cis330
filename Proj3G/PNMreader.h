/* PNMreader.h
reader class for fstream, takes in filename for constructor 
and inherits from Source */

#include <source.h>

class PNMreader : public Source {
	protected:
		char *filename;
	public:
		PNMreader(const char *f);
		~PNMreader();
		virtual void Execute();
		virtual const char *SourceName();
};


