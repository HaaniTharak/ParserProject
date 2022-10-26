#include "Stmt.h"

class Jump: public STMT
{
    public: 
    Jump();
    virtual string Printer();
    int jump_loc;
};