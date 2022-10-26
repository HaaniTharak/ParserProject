#include "Stmt.h"

//Constructor:
STMT::STMT()
{
    return;
}
/*BASE class, defines Printer which gets overwritten by the Derived classes for example Add, Start, PushI etc.
(check the .h files)
 and prints for the instruction buffer, for each specific command parsed i.e add, start, pushi etc.
*/
//NOTE: THIS SHOULD NEVER PRINT, IF IMPLEMENTED CORRECTLY!!!
string STMT::Printer()
{
    cerr << "Default String, Base case Printed!!!\n";
    return "";
}