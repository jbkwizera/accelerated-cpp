// main.cpp - unit tests
#include <iostream>
#include <string>
#include <vector>
#include "strsplit.h"

using std::cout;        using std::string;
using std::cin;         using std::vector;
using std::endl;

int main()
{
    string s;

    while (getline(cin, s)) {
        vector<string> res = strsplit(s);
        for (auto word: res)
            cout << word << endl;
    }

    return 0;
}
