#include "StringBuffer.h"
#include "Prints.h"

Prints::Prints(int i)
{
    count = i;
    return;
}

string Prints::Printer()
{
    string str = "Prints ";
    //str += print_val;
    auto s = to_string(count);
    str += s;
    return str;
}