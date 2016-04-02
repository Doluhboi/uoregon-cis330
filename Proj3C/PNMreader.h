#include <source.h>

/* PNMreader class, takes in filename for constructor - inherits from Source */
class PNMreader : public Source {
	protected:
		char *filename;
	public:
		PNMreader(char *f) {
			filename = (char *) malloc(strlen(f+1));
            strcpy(filename, f);
		}
        ~PNMreader() {
            free(filename);
        }
		virtual void Execute();
};


