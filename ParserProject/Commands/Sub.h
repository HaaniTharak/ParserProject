#include "InstructionBuffer.h"

class Sub: public STMT
{
    public:
    Sub();
    virtual string Printer();
    string add_string;
};