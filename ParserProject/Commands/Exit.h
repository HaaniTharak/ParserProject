#include "InstructionBuffer.h"

class Exit: public STMT
{
    public:
    //Constructor:
    Exit();
    virtual string Printer();
};