#ifndef _HELPER_
#define _HELPER_
#include "Parser.h"
#include <string>
#include <vector>

/*This file Contains functions to help run code in the main*/

//This function helps in Error checking the input:
int ErrorChecking(char* arg);

//This function does the heavey lifting for the parser, and calls and runs a a majority of the code:
void ReadCommand(string line, InstructBuf* ibuf, StringBuf* sbuf);


#endif 