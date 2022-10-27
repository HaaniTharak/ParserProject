#ifndef PRINTS_H_
#define PRINTS_H_
#include "Stmt.h"
#include <iostream>
#include <string>

using namespace std;

class Prints: public STMT
{
    public:
    //Constructor:
    Prints(int i);
    virtual string Printer();
    string print_val;
    int count = -1; 
};

#endif