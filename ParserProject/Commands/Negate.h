#include "InstructionBuffer.h"

class Negate: public STMT
{
    public:
    Negate();
    virtual string Printer();
};