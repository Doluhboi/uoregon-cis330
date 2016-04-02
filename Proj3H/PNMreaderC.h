/* PNMreaderC.h 
reader class which takes in filename for the constructor 
and inherits from Source */

#include <source.h>

class PNMreaderC : public Source {
	protected:
    	char *filename;
	public:
    	PNMreaderC(char *f);
    	~PNMreaderC();
    	
		virtual void Execute();
};
