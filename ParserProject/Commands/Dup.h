#include "InstructionBuffer.h"

class Dup: public STMT
{
    public:
    Dup();
    virtual string Printer();
};