#include "InstructionBuffer.h"


class PushI: public STMT
{
    public:
    
    virtual string Printer();
    int i; //Stores what was pushed
};