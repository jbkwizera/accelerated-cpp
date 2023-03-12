// sentence-gen.cpp
#include <iostream>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include "strsplit.h"
#include "sentence-gen.h"

using std::string;      using std::vector;
using std::map;         using std::ifstream;

bool bracketed(const string& t)
{
    string::size_type n = t.size();
    return n > 0 && t[0] == '<' && t[n-1] == '>';
}

int nrand(int n)
{
    const int bucket_size = RAND_MAX / n;
    int r;
    do r = rand() / bucket_size;
    while (r >= n);
    return r;
}

map<string, vector<vector<string>>>
    read_grammar(ifstream& ifs)
{
    map<string, vector<vector<string>>> result;
    string line;

    while (getline(ifs, line)) {
        vector<string> entry = strsplit(line);
        if (!entry.empty())
            result[entry[0]].push_back(
                    vector<string>(entry.begin() + 1, entry.end()));
    }
    return result;
}

void generate(
    const map<string, vector<vector<string>>>& grammar,
    const string& category,
    vector<string>& result)
{
    const vector<vector<string>>& rules =
        grammar.find(category)->second;
    const vector<string>& current_rule =
        rules[nrand(rules.size())];

    for (auto token: current_rule)
        if (bracketed(token))
            generate(grammar, token, result);
        else
            result.push_back(token);
}

vector<string> generate(
    const map<string, vector<vector<string>>>& grammar,
    const string& category)
{
    vector<string> result;
    generate(grammar, category, result);
    return result;
}
