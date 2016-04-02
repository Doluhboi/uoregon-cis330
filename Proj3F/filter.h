/*filter.h
filter class inherits from Source and Sink */
#include <source.h>
#include <sink.h>
#include <image.h>

class Filter : public Source, public Sink {
	public:
		virtual void Update();
		virtual const char *FilterName() = 0;
		virtual const char *SourceName();
		virtual const char *SinkName();
};


