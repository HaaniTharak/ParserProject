#include "Stmt.h"


class PushI: public STMT
{
    public:
    PushI();
    virtual string Printer();
    int i; //Stores what was pushed
};