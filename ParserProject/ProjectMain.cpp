#include "ProjectMain.h"
#include "Parser.h"
#include <vector>

//#if 0
static int ErrorChecking(char* arg);
static int ErrorChecking(char* arg)
{
    fstream inputfile;
    string line;
    string lower;
    string sec_line;
    inputfile.open(arg);
    vector<string> vec;
    if(inputfile.is_open()){
        //Converts into lower case and adds to a vector:
        int i = 0;
        while (getline(inputfile,line)){
            lower = line; string::iterator character = lower.begin();
            while(character != lower.end()){
                *character = tolower(*character);
                character++;
            }
            vec.push_back(lower);
            //cerr << vec[i] <<"\n";
            i++;
        }
        if(vec[vec.size()-1] != "end"){cerr << "Program did not end in END!!!\n";return ERROR; }
        
        for(i = 0; i < vec.size();i++){
            line = vec[i];
            //line = lower;
            //Read in the instructions HERE:
            if(i == 0 && line != "start"){cerr<<"Start does not begin the program!!!\n";return ERROR;}
            if(i == 0 && line == "end"){cerr<<"The program start with end!!!\n";return ERROR;}
            if(line == "start"){
                for(int j = 1; j<vec.size()-1;j++){
                    sec_line = vec[j];
                    if(sec_line == "start"){cerr << "BOTH are start!!!\n"; return ERROR;}
                }       
            }
            //if(i != 0 && line == "end"){return ERROR;}
            //cerr << line << "\n"; //TEST STATEMENT
        }
        //Close the input file:
        inputfile.close();
    }
    return NOERROR;
}
//#endif

static void ReadCommand(string line);
static void ReadCommand(string line, InstructBuf* ibuf)
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
    
    /*----------------------------------------------------------Get the Flag:----------------------------------------------------------*/
    string parsed_command;
    int flag = obj.GetFlag(lower, &parsed_command);
    obj.BuildStmt(flag, lower, parsed_command, ibuf);

    //cerr << "Instruction Size: " << ibuf->inst_buffer.size() << "\n";
    //cerr << "INST BUFFER: " << ibuf->inst_buffer[0]->Printer()<< "\n";
}

int main(int argc, char* argv[])
{
    //Check if the number arguments are correct:
    if(argc != 3){//Remember the executable is one
        cerr << "Incorrect number of arguments\n";
        cerr << "g++ -std=c++11 *.cpp\n";
        cerr << "./a.out practice_case.txt prac_out.txt \n";
        return EXIT_FAILURE;
    }
    //Error checking
   // ErrorChecking(argv[1]);

    //Open an input file:
    fstream inputfile;
    ofstream outfile;
    string line;
    string newname  = argv[1];
    newname += ".pout";
    InstructBuf* ibuf = new InstructBuf();
    int is_valid = NOERROR;

    inputfile.open(argv[1]);
    //IF the file is open:
    if(inputfile.is_open()){
        is_valid = ErrorChecking(argv[1]);
        if(is_valid == ERROR){cerr << "ERROR!!! INVALID INPUT!!!\n";outfile.open(argv[2]); outfile.close(); return EXIT_FAILURE;}
        

        while(getline(inputfile,line)){
            //Read in the instructions HERE:
            ReadCommand(line, ibuf);
            //cerr << line << "\n"; //TEST STATEMENT
        }
        //Write to the outputfile for step2:
        //Open the output file:
        outfile.open(newname);
        int i = 0;
        while(i < ibuf->inst_buffer.size()){
            outfile << ibuf->inst_buffer[i]->Printer(); 
            i++;
            //MAy need ths:
            //if(i != ibuf->inst_buffer.size()){}
            outfile << "\n"; 
        }
        //Close the input and output files:
        inputfile.close();
        outfile.close();
    }
    else{ 
        cerr << "Error opening the inputfile!!!\n";
        return EXIT_FAILURE;
    }
    return  EXIT_SUCCESS;
}