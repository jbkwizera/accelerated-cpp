// str-split.cpp: taking strings apart
#include <cctype>
#include "strsplit.h"

using std::vector;
using std::string;

vector<string> strsplit(const string& s)
{
    vector<string> ret;
    string::size_type i = 0;
    
    while (i != s.size()) {
        while (i != s.size() && isspace(s[i]))
            ++i;
        
        string::size_type j = i;
        while (j != s.size() && !isspace(s[j]))
            ++j;
        
        if (i != j) {
            ret.push_back(s.substr(i, j - i));
            i = j;
        }
    }
    return ret;
}
