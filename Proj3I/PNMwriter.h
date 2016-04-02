/* PNMwriter.h
uses fstream */
#include <sink.h>

/* PNMwriterCPP inherits from Sink */
class PNMwriter : public Sink {
	public:
		void Write(const char *filename);
        virtual const char *SinkName() { return "PNMwriter"; }
};


