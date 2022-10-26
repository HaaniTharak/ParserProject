#ifndef _PushI_
#define _PushI_

#include "Stmt.h"
#include <string>


class PushI: public STMT
{
    public:
    PushI();
    virtual string Printer();
    string push_var; //Stores what was pushed
};
#endif