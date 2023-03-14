// sentence-gen-test.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>
#include <list>
#include "sentence-gen.h"

using std::cout;        using std::cin;
using std::ifstream;    using std::endl;
using std::vector;      using std::string;
using std::map;         using std::back_inserter;
using std::list;        using std::ostream_iterator;

int main(int argc, const char* argv[])
{
    ifstream ifs(argv[1]);
    map<string, vector<vector<string>>> grammar;
    grammar = read_grammar(ifs);

    string category;
    while (cin >> category) {
        list<string> text;
        generate(grammar, category, back_inserter(text));
        copy(text.begin(), text.end(), ostream_iterator<string>(cout, " "));
        cout << endl;
    }

    return 0;
}
