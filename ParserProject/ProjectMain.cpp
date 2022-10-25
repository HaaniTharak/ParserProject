#include "ProjectMain.h"
#include "Parser.h"
#include <vector>

void ReadCommand(string line);
void ReadCommand(string line)
{
    //cerr << "CONSTRUCTED!!!\n";
    Parser obj;
    //Convert instructions to lowercase(For consistentcy in program):
    string lower = line;
    string::iterator character = lower.begin();
    while(character != lower.end()){
        *character = tolower(*character);
        character++;
    }
    //cerr << "Lower: " << lower << "\n";
    //cerr << "Line: " << line << "\n";
    /*Get the Flag:*/

    string parsed_command;
    vector<STMT*> inst_buffer;
    int flag = obj.GetFlag(lower, &parsed_command, inst_buffer );


    cerr << "Parsed Command: " << parsed_command << "\n";
    //obj.BuildStmt(flag, lower, parsed_command);

    /**/
}

int main(int argc, char* argv[])
{
    //Check if the number arguments are correct:
    if(argc != 3){//Remember the executable is one
        cerr << "Incorrect number of arguments\n";
        return EXIT_FAILURE;
    }
    //Open an input file:
    fstream inputfile;
    string line;
    inputfile.open(argv[1]);
    //IF the file is open:
    if(inputfile.is_open()){
        while(getline(inputfile,line)){
            //Read in the instructions HERE:
            ReadCommand(line);
            //cerr << line << "\n"; //TEST STATEMENT
        }
        //Close the input file:
        inputfile.close();
    }
    else{ 
        cerr << "Error opening the inputfile!!!\n";
        return EXIT_FAILURE;
    }

    return  EXIT_SUCCESS;
}