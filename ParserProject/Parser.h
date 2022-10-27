#ifndef PARSER
#define PARSER
#include "InstructionBuffer.h"
#include "StringBuffer.h"
#include "Stmt.h"
#include <cctype>
#include <cstring>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

//DEFINE DECLARATIONS:
//Error(Invalid Input), If this occurs then it should return EXIT_FAILURE:
#define ERROR -1
//Valid Input:
#define NOERROR 0

//Flag for each set of commands and labels:
#define NONE_FLAG 1
#define PUSHI_FLAG 2
#define PRINT_FLAG 3
#define DECLAR_FLAG 4
#define SCALAR_FLAG 5
#define LABEL_FLAG 6
#define END_FLAG 7

/*
  This class will hold the main functions and objects that will run the parser
  and execute the instruction cod eint he input file:
*/
class Parser
{
    public:
    // Have not used these Variables but they may be needed later for the error cases!!!:
    int start_exist = 0; //Set start to false
    int end_exist = 0; //Set end to false

    //Constructor:
    Parser();
    /*Get flag/designation of command to be run, ensure code quality
    and ease of implementation by defining the types*/
    int GetFlag(string line, string* parsed_command);
    //Create and  Build STMT:
    void BuildStmt(int flag, string line, string command,InstructBuf* ibuf, StringBuf* sbuf);
};


#endif 