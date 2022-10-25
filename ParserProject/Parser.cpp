#include "Parser.h"
#include "InstructionBuffer.h"
#include <vector>
#include <cctype>
#include <cstring>

//Constructor:
Parser::Parser()
{
    return;
}

int Parser::GetFlag(string entry, string* parsed_command)
{
    int flag;
    //Getting the first command(Before the first whitespace):
    string temp = entry;
    string::iterator character = temp.begin(); 
    string before_whitespace = ""; int is_parameter = 0; //Is there another parameter?
    while(character != temp.end()){
        if(isspace(*character) || *character == '\n'){
            //cerr << *character << "\n";
            if(*character != '\n'){
                //cerr << "There is another character!!!" << *character << "\n";
                //There is another parameter:
                is_parameter = 1;  
            }
            break;
        }
        before_whitespace += (*character);
        character++;
    }
    //cerr << "Before: " << before_whitespace << "\n";
    string command = before_whitespace; 
    *parsed_command = command;
    //cerr << "Command: " << command << "\n";
    
    /*------------------------------ FLAG CHECKING: ------------------------------*/
    //IF the NONE_FLAG:
    if (command == "start" || command == "exit" || command == "dup" || command == "add" || 
        command == "negate" || command == "mul" || command == "div" || command == "printtos" || 
        command == "pop" || command == "swap" || command == "return"){
        flag = NONE_FLAG;
    }
    //IF the PUSHI_FLAG:
    else if(command == "pushi"){
        //cerr << "PUSHI\n";
        flag = PUSHI_FLAG;
    }
    //IF the PRINT_FLAG:
    else if (command == "prints"){
        flag = PRINT_FLAG;
    }
    //IF DECLAR_FLAG:
    else if(command == "declarr"){
        flag = DECLAR_FLAG;
    }
    //IF SCALAR_FLAG:
    else if(command == "declscal" || command == "pushscal" || command == "popscal" || command == "pusharr" || command == "poparr"){
        flag = SCALAR_FLAG;    
    }
    //IF LABEL_FLAG:
    else if(command == "label" || command == "gosub" || command == "gosublabel" || command == "jump" || command == "jumpnzero" || command == "jumpzero") {
        flag = LABEL_FLAG;
    }
    //IF END_FLAG:
    else if (command == "end") {flag = END_FLAG;}
    //Fail case might be needed, just in case invalid instructions are added??
    //cerr << flag << "\n";
    cerr << "Command: " <<command << "\n";
    return flag;
}

#if 0 
    NEXT STEP IS TO CREATE ALL THE FILES LIKE ADD,MUL,DIV ETC AND HAVE THEM ADD AND PRINT TO THE 
    EACH COMMAND OR BE ADDED TO THE INSTRUCTION BUFFER, SYMBOL TABLE OR STRING BUFFER ETC.

#endif


void BuildStmt(int flag, string line, string command, vector<STMT*> inst_buffer)
{
    cerr << "BUILDING THE STMT!!!\n";

    //Instructional Buffer:
    inst_buffer.push_back(command);
    cerr << "INST BUFFER: " << inst_buffer[0] << "\n";


    //Create stmt variable:
    STMT* stmt = nullptr;

    /*Count the number of paramters for the command, by counting whitespace:
    //Count how many parameters there are, if 2 whitepsaces, then it means;
    //One command and 2 extra parameters...I think?*/
    int num_whitespace = 0; string::iterator character = line.begin();
    while(character != line.end()){
        if(isspace(*character)){num_whitespace += 1;}
        character++;
    }
    //cerr << "Number of WhiteSpace: " << num_whitespace << "\n";

#if 0
    switch(flag)
    {
        case(NONE_FLAG):
            if(command == "start"){start = new Start(); stmt = start;break;}
            if(command == "exit"){stmt = new Exit(); break;}
            if(command == "pop"){stmt = new Pop();break;}
            if(command == "dup"){stmt = new Dup();break;}
            if(command == "swap"){stmt = new Swap();break;}
            if(command == "add"){stmt = new Add();break;}
            if(command == "negate"){stmt = new Negate();break;}
            if(command == "mul"){stmt = new Mul();break;}
            if(command == "div"){stmt = new Div();break;}
            if(command == "return"){stmt = new PrintTos();break;}
            //Need Symbol Table:
            //if(command == "return"){stmt = new Return();break;}
        case(PUSHI_FLAG):
            if(command == "pushi"){
                cerr << "Pushi in STMT\n";
                break;
            }
            break;
        case(PRINT_FLAG):
            if (command == "prints"){
                //SYMBOL TABLE
                cerr << "Prints in STMT\n";
                break;
            }
        case(DECLAR_FLAG):
            if(command == "declarr"){
                //SYMBOL TABLE ???
                cerr << "Declarer in STMT\n";
                break;
            }
        case(SCALAR_FLAG):
            if(command == "declscal" || command == "pushscal" || command == "popscal" || command == "pusharr" || command == "poparr"){
                //NEED TO WRITE:
                cerr << "SCALAR in STMT\n";
                break;
            }
        case(LABEL_FLAG):
            if(command == "label" || command == "gosub" || command == "gosublabel" || command == "jump" || command == "jumpnzero" || command == "jumpzero"){
                cerr << "Label is running\n";
                break;
            }
        case(END_FLAG):
            if (command == "end"){
                //End
                cerr << "End\n";
                break;
            }

    }
#endif 

}