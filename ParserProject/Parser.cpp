#include "Parser.h"

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


void Parser::BuildStmt(int flag, string line, string command, InstructBuf* ibuf)
{
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
    switch(flag)
    {
        case(NONE_FLAG):
            if(command == "start"){Start* start = new Start(); stmt = start; ibuf->inst_buffer.push_back(start); break;}
            if(command == "exit"){Exit* stmt = new Exit(); ibuf->inst_buffer.push_back(stmt);break;}
            if(command == "pop"){Pop* stmt = new Pop(); ibuf->inst_buffer.push_back(stmt); break;}
            if(command == "dup"){Dup* stmt = new Dup(); ibuf->inst_buffer.push_back(stmt); break;}
            if(command == "swap"){Swap* stmt = new Swap(); ibuf->inst_buffer.push_back(stmt); break;}
            if(command == "add"){Add* stmt = new Add(); ibuf->inst_buffer.push_back(stmt); break;}
            if(command == "negate"){ Negate* stmt = new Negate(); ibuf->inst_buffer.push_back(stmt); break;}
            if(command == "mul"){Mul* stmt = new Mul(); ibuf->inst_buffer.push_back(stmt); break;}
            if(command == "div"){Div* stmt = new Div(); ibuf->inst_buffer.push_back(stmt); break;}
            if(command == "printtos"){PrintTos* stmt = new PrintTos(); ibuf->inst_buffer.push_back(stmt); break;}
            //Need Symbol Table:
            //if(command == "return"){stmt = new Return();break;}
        case(PUSHI_FLAG):
            if(command == "pushi"){
                cerr << "Pushi in STMT\n";
                PushI* push = new PushI();
                int idx = line.find_first_of(" ");
                push->push_var = line.substr(idx+1);
                ibuf->inst_buffer.push_back(push);
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
                //End:
                //End* end = new End(); ibuf->inst_buffer.push_back(end); break;
                cerr << "End\n";
                break;
            }

    }
    //cerr << "INST BUFFER: " << ibuf->inst_buffer[0]->Printer()<< "\n";
    //cerr << "HERE1!!!!!!!!!!!!!!!!!!!!!!!!!!";
}