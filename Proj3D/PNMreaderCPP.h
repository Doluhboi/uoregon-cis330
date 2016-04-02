#include <source.h>

/* PNMreaderCPP class, takes in filename for constructor 
		- inherits from Source */

class PNMreaderCPP : public Source {
	protected:
		char *filename;
	public:
		PNMreaderCPP(char *f) {
			filename = (char *) malloc(strlen(f));
			strcpy(filename, f);
		}
		~PNMreaderCPP() {
			free(filename);
		}	
		virtual void Execute();
};


