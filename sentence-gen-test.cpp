// sentence-gen-test.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include "sentence-gen.h"

using std::cout;        using std::cin;
using std::ifstream;    using std::endl;
using std::vector;      using std::string;
using std::map;

int main(int argc, const char* argv[])
{
    ifstream ifs(argv[1]);
    map<string, vector<vector<string>>> grammar;
    grammar = read_grammar(ifs);

    string category;
    while (cin >> category) {
        vector<string> text = generate(grammar, category);
        for (auto word: text)
            cout << word << " ";
        cout << endl;
    }

    return 0;
}
