#ifndef _STRINGBUFFER_
#define _STRINGBUFFER_

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class StringBuf
{

    public:
    //Constructor:
    StringBuf();
    //StringBuf* strbuf;
    vector<string> str_buffer;
    //Geter:
    StringBuf* getSBuf();
    //Append:
    void AppendString(string str);

};




#endif