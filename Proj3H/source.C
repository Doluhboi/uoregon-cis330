/* source.C  
methods for Source class */
#include <source.h>
#include <logging.h>

Source::Source() {
	img.setSource(this);
}	
Source::~Source() { }
	
Image * Source::GetOutput() {
	return &img;
}

void Source::Update() {
	char msg[128];
	sprintf(msg, "%s: about to execute", SourceName());
	Logger::LogEvent(msg);
	Execute();
	sprintf(msg, "%s: done executing", SourceName());
	Logger::LogEvent(msg);
}
