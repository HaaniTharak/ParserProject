#ifndef PARSER
#define PARSER
#include "InstructionBuffer.h"
#include "Stmt.h"
#include <cctype>
#include <cstring>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

#define NONE_FLAG 1
#define PUSHI_FLAG 2
#define PRINT_FLAG 3
#define DECLAR_FLAG 4
#define SCALAR_FLAG 5
#define LABEL_FLAG 6
#define END_FLAG 7

class Parser
{
    public:
    //Variables:
    int start_exist = 0; //Set start to false
    int end_exist = 0; //Set end to false
    // string parsed_command;

    //Constructor:
    Parser();
    /*Get flag/designation of command to be run, ensure code quality
    and ease of implementation by defining the types*/

    

    int GetFlag(string line, string* parsed_command);
    //Create and STMT:
    void BuildStmt(int flag, string line, string command,vector<STMT*> inst_buffer);
};
#endif 