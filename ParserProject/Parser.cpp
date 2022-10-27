#include "Parser.h"

// Constructor:
Parser::Parser() { return; }

/* Parameters for GetFlag:
 entry is the entire line read from the file,
 parsed_command is the command read from the file to be returned to the caller function by address
 */
int Parser::GetFlag(string entry, string *parsed_command)
{
    //Stores what type of command it is:
    int flag;
    /*-----------------------------------Getting the First Command(Before the first whitespace):-----------------------------------*/
    string temp = entry; //Store the entire line read in, so it can iterate through to get the parameter
    string::iterator character = temp.begin(); //Iterator to go through each character in the string
    string before_whitespace; //Meant to store the command before the whitespace
    int is_parameter = 0; // Is there another parameter? (Not sure if I need this, mainly done to check how many parameters there are)
    //Iterate throught the line till the first whitespace or end of line character is found:
    while (character != temp.end())
    {
        if (isspace(*character) || *character == '\n'){
            if (*character != '\n'){
                // cerr << "There is another character!!!" << *character << "\n";
                // There is another parameter:
                is_parameter = 1;
            }
            break;
        }
        before_whitespace += (*character);
        character++;
    }
    // cerr << "Before: " << before_whitespace << "\n";
    string command = before_whitespace; //Command found and set
    *parsed_command = command; //Command Stored to be returned by address

    /*--------------------------------------------------------FLAG CHECKING:--------------------------------------------------------*/
    // IF the NONE_FLAG:
    if (command == "start" || command == "exit" || command == "dup" || command == "add" ||
        command == "negate" || command == "mul" || command == "div" || command == "printtos" ||
        command == "pop" || command == "swap" || command == "return"){
        flag = NONE_FLAG;
    }
    // IF the PUSHI_FLAG:
    else if (command == "pushi"){
        // cerr << "PUSHI\n";
        flag = PUSHI_FLAG;
    }
    // IF the PRINT_FLAG:
    else if (command == "prints"){
        flag = PRINT_FLAG;
    }
    // IF DECLAR_FLAG:
    else if (command == "declarr"){
        flag = DECLAR_FLAG;
    }
    // IF SCALAR_FLAG:
    else if (command == "declscal" || command == "pushscal" || command == "popscal" || command == "pusharr" || command == "poparr"){
        flag = SCALAR_FLAG;
    }
    // IF LABEL_FLAG:
    else if (command == "label" || command == "gosub" || command == "gosublabel" || command == "jump" || command == "jumpnzero" || command == "jumpzero"){
        flag = LABEL_FLAG;
    }
    // IF END_FLAG:
    else if (command == "end"){
        flag = END_FLAG;
    }
    // Fail case might be needed, just in case invalid instructions are added??
    return flag;
}

/*Parameters for BuildStmt
    Flag for each set of commands and labels:
    line is the ENTIRE line parsed from the file eg. start then the line = start, eg2. pushi 3 then the line = pushi 3
    command is the command parsed from the file eg. add then command = add, eg2. pushi 3 then command = pushi,
    ibuf is the object to hold the Instruction Buffer, check the function to see how we use it to Print the insturction buffer 
*/
void Parser::BuildStmt(int flag, string line, string command, InstructBuf *ibuf, StringBuf* sbuf)
{
    // Create stmt variable:
    STMT* stmt;
    int idx;

    /*Count the number of paramters for the command, by counting whitespace:
    //Count how many parameters there are, if 2 whitepsaces, then it means;
    //One command and 2 extra parameters...I think?*/
    int num_whitespace = 0;
    string::iterator character = line.begin();
    while (character != line.end()){
        if (isspace(*character)){num_whitespace += 1;}character++;
    } //This while may be unecessary but may be used later, it can be used to count how many parameters there if needed, as explained above
    // cerr << "Number of WhiteSpace: " << num_whitespace << "\n";
    
    /*----------------------------------------------PARSE & EXECUTE what parsed COMMANDS----------------------------------------------*/
        /*====================================Using the flag determine which COMMAND to run====================================*/
            /* INSTRUCTIONS ON WHAT TO ADD IN THIS FILE
             Need to create the string buffer and symbol table stuff for these functions ,
             create the string buffer first ensure it works then make it work with the symbol table,
             (For ease anything using the symbol table to be coded later has "SYMBOL TABLE" written in comments with)
              NOTE: Return command needs to be written requires a symbol table for subroutines, needs to be done at the end!!!!!!!!
            */
    switch (flag)
    {
    case (NONE_FLAG):
        if (command == "start"){
            Start *start = new Start();
            ibuf->inst_buffer.push_back(start);
            break;
        }
        if (command == "exit"){
            Exit *stmt = new Exit();
            ibuf->inst_buffer.push_back(stmt);
            break;
        }
        if (command == "pop"){
            Pop *stmt = new Pop();
            ibuf->inst_buffer.push_back(stmt);
            break;
        }
        if (command == "dup"){
            Dup *stmt = new Dup();
            ibuf->inst_buffer.push_back(stmt);
            break;
        }
        if (command == "swap"){
            Swap *stmt = new Swap();
            ibuf->inst_buffer.push_back(stmt);
            break;
        }
        if (command == "add"){
            Add *stmt = new Add();
            ibuf->inst_buffer.push_back(stmt);
            break;
        }
        if (command == "negate"){
            Negate *stmt = new Negate();
            ibuf->inst_buffer.push_back(stmt);
            break;
        }
        if (command == "mul"){
            Mul *stmt = new Mul();
            ibuf->inst_buffer.push_back(stmt);
            break;
        }
        if (command == "div"){
            Div *stmt = new Div();
            ibuf->inst_buffer.push_back(stmt);
            break;
        }
        if (command == "printtos"){
            PrintTos *stmt = new PrintTos();
            ibuf->inst_buffer.push_back(stmt);
            break;
        }
        // Need Symbol Table:
        //Return command needs to be written requires a symbol table for subroutines, needs to be done at the end!!!!!!!!
        // if(command == "return"){stmt = new Return();break;}
    case (PUSHI_FLAG):
        if (command == "pushi"){
            cerr << "Pushi in STMT\n";
            PushI *push = new PushI();
            idx = line.find_first_of(" ");
            push->push_var = line.substr(idx + 1);
            ibuf->inst_buffer.push_back(push);
            break;
        }
        break;
    case (PRINT_FLAG):
        if (command == "prints"){
            // SYMBOL TABLE
            cerr << "Prints in STMT\n";
            Prints* stmt = new Prints(sbuf->str_buffer.size()-1);
            idx = line.find_first_of(" ");
            stmt->print_val = line.substr(idx + 1);
            stmt->count += 1; //Increment by one
            ibuf->inst_buffer.push_back(stmt);
            sbuf->str_buffer.push_back(stmt->print_val);

            cerr<<"COUNT: " << stmt->count<<"\n";
            cerr<<"BUFFER Size: "<< sbuf->str_buffer.size()<< "\n";
            //for(int i = 0; i < sbuf->str_buffer.size();i++){cerr<<"PRINTS BUFFER: "<< sbuf->str_buffer[i] << "\n";} //This just tests if the buffer is filled correctly
            //This needs to be the 
            break;
        }
    case (DECLAR_FLAG):
        if (command == "declarr"){
            // SYMBOL TABLE ???
            cerr << "Declarer in STMT\n";
            break;
        }
    case (SCALAR_FLAG):
        if (command == "declscal" || command == "pushscal" || command == "popscal" || command == "pusharr" || command == "poparr"){
            // NEED TO WRITE:
            cerr << "SCALAR in STMT\n";
            break;
        }
    case (LABEL_FLAG):
        if (command == "label" || command == "gosub" || command == "gosublabel" || command == "jump" || command == "jumpnzero" || command == "jumpzero"){
            cerr << "Label is running\n";
            break;
        }
    case (END_FLAG):
        if (command == "end"){//If end gets parsed, then ignore it and do NOTHING!!!
            cerr << "End\n";
            break;
        }
    }
}