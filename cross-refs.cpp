// cross-refs.cpp
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "strsplit.h"

using std::string;  using std::vector;
using std::map;     using std::cin;
using std::istream;

map<string, vector<int>>
    xref(istream& in,
         vector<string> find_words(const string&) = strsplit)
{
    string line;
    string::size_type line_number = 0;
    map<string, vector<int>> result;

    while (getline(in, line)) {
        ++line_number;
        vector<string> words = find_words(line);
        for (auto word: words)
            result[word].push_back(line_number);
    }
    return result;
}
