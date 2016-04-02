/* PNMwriterC.h 
writer class inherits from Sink */

#include <sink.h>

/* PNMwriter inherits from Sink */
class PNMwriterC : public Sink {
public:
    void Write(char *filename);
};
