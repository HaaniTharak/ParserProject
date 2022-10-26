#include "Jump.h"

Jump::Jump()
{
    return;
}

string Jump::Printer()
{
    string temp = "Jump, ";
    temp += jump_loc;
    return temp;
}
