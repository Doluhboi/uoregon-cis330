/* filter.C 
Update method for filter class */
#include <filter.h>

int updateCounter;

void Filter::Update() {
	char msg[128];
    updateCounter++;
    
	if(updateCounter > 1000) {
        sprintf(msg, "%s: stack overflow!", FilterName());
		DataFlowException e(FilterName(), msg);
		throw e;
	}

	// Update img1
	if(img1 != NULL) {
		sprintf(msg, "%s: about to update input1", FilterName());
		Logger::LogEvent(msg);
		img1->Update();
		sprintf(msg, "%s: done updating input1", FilterName());
		Logger::LogEvent(msg);
	}

	// Update img2
	if(img2 != NULL) {
		sprintf(msg, "%s: about to update input2", FilterName());
		Logger::LogEvent(msg);
		img2->Update();
		sprintf(msg, "%s: done updating input2", FilterName());
		Logger::LogEvent(msg);
	}

	// Execute
	sprintf(msg, "%s: about to execute", FilterName());
	Logger::LogEvent(msg);
	Execute();	
	sprintf(msg, "%s: done executing", FilterName());
	Logger::LogEvent(msg);
}

const char *Filter::SourceName() {
	return FilterName();
}

const char *Filter::SinkName() {
	return FilterName();
}
