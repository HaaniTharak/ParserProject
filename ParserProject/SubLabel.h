#include "Stmt.h"

class SubLabel: public STMT
{   
    public:
    SubLabel();
    virtual string Printer();
    string add_string;
};