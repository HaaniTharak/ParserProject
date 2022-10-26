#ifndef _STMT_
#define _STMT_

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class STMT
{
    public:
    //Constructor:
    STMT();
    //Print the number
    virtual string Printer() = 0;
    
    string stmt_command;
};

#endif