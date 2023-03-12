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

unsigned int get_random(unsigned int a, unsigned int b)
{
    return a + rand() % (b - a);
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

vector<string> generate(
    const map<string, vector<vector<string>>>& grammar,
    const string& category)
{
    vector<string> result;
    vector<vector<string>> rules = 
        grammar.find(category)->second;
    vector<string> remaining = 
        rules[get_random(0, rules.size())];

    while (!remaining.empty()) {
        string current_token = remaining.back();
        remaining.pop_back();
        
        if (!bracketed(current_token))
            result.push_back(current_token);
        else {
            vector<vector<string>> matches = 
                grammar.find(current_token)->second;
            vector<string> resolved =
                matches[get_random(0, matches.size())];

            for (auto token: resolved)
                remaining.push_back(token);
        }
    }
    reverse(result.begin(), result.end());

    return result;
}
