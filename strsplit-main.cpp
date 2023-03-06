#include <iostream>
#include <vector>
#include <string>
#include "strsplit.h"

using std::cout;        using std::endl;
using std::vector;      using std::string;

int main(int argc, char *argv[]) 
{
    string s;
    while (getline(std::cin, s)) {
        vector<string> words = strsplit(s);
        for (vector<string>::size_type i = 0; i != words.size(); i++)
            cout << words[i] << endl;
    }
    return 0;
}
