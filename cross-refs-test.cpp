// cross-ref.cpp
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include "cross-refs.h"

using std::cout;        using std::cin;
using std::endl;        using std::vector;
using std::string;      using std::map;
using std::istream;     using std::setw;
using std::left;        using std::right;

int main()
{
    map<string, vector<int>> refs = xref(cin);
    string::size_type wordlen = 12;

    for (auto entry: refs) {
        cout << left << setw(wordlen)
             << entry.first;

        for (auto p: entry.second)
            cout << right << setw((p != entry.second[0]) * wordlen + 3)
                 << p << endl;
        cout << endl;
    }

    return 0;
}
