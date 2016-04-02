#include <sink.h>

/* PNMwriter inherits from Sink */
class PNMwriter : public Sink {
public:
    void Write(char *filename);
};
