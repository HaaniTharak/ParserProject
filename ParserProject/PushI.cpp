#include "PushI.h"

PushI::PushI()
{
    return;
}

string PushI::Printer()
{
    //return "PUSH I\n";
    string str = "PushI (";
    str += push_var;
    str += ")";
    return str;
}