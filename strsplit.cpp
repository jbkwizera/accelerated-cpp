// strsplit.cpp: taking strings apart
#include <algorithm>
#include <cctype>
#include "strsplit.h"

using std::vector;
using std::string;
using std::find_if;

bool space(char c)
{
    return isspace(c);
}

bool not_space(char c)
{
    return !isspace(c);
}

vector<string> strsplit(const string& s)
{
    vector<string> ret;
    string::const_iterator i = s.begin();
    
    while (i != s.end()) {
        i = find_if(i, s.end(), not_space);

        string::const_iterator j = find_if(i, s.end(), space);

        if (i != s.end())
            ret.push_back(string(i, j));
        i = j;
    }
    return ret;
}
