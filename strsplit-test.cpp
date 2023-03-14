// main.cpp - unit tests
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include "strsplit.h"

using std::cout;        using std::string;
using std::cin;         using std::vector;
using std::endl;        using std::back_inserter;

int main()
{
    string s;

    while (getline(cin, txt)) {
        vector<string> res;
        strsplit(txt, back_inserter(res));
        for (auto word: res)
            cout << word << endl;
    }

    return 0;
}
