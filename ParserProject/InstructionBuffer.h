#ifndef _INSTRUCTIONBUFFER_ 
#define _INSTRUCTIONBUFFER_ 
#include "Stmt.h"

//For Instruction Buffer:
#include "Add.h"
#include "Declscal.h"
#include "Div.h"
#include "Dup.h"
#include "End.h"
#include "Exit.h"
#include "Jump.h"
#include "Mul.h"
#include "Negate.h"
#include "Pop.h"
#include "PrintTos.h"
#include "PushI.h"
#include "Start.h"
#include "Sub.h"
#include "SubLabel.h"
#include "Swap.h"

//For String Buffer:
#include "Prints.h"



#include <iostream>
#include <fstream>
#include <string>
#include <vector>
/*THIS CONTAINS THE INSTRUCTION BUFFER WHICH IS STORED IN A VECTOR:*/
class InstructBuf
{
    public:
    //Create constructor:
    InstructBuf();
    vector<STMT*> inst_buffer;
};
#endif 