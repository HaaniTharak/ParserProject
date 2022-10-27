#include "StringBuffer.h"

StringBuf::StringBuf()
{
    return;
}

void StringBuf::AppendString(string str)
{
    str_buffer.push_back(str);

}