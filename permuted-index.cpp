/* permutated-index.cpp: a permuted index is one in which each phrase is
 * indexed by every word in the phrase
 */
#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>
#include <vector>
#include <algorithm>
#include "strsplit.h"

using std::cout;        using std::endl;
using std::cin;         using std::string;
using std::vector;      using std::setw;
using std::sort;        using std::max;
using std::left;        using std::right;

struct Record
{
    const string* ref;
    string::size_type position;
};

bool compare(const Record& x, const Record& y)
{
    string _x = *(x.ref);
    for (auto& c: _x) c = tolower(c);
    
    string _y = *(y.ref);
    for (auto& c: _y) c = tolower(c);

    return _x.substr(x.position) < _y.substr(y.position);
}

void add_rotations(vector<Record>& index, const string& s)
{
    Record entry;
    string::size_type i = 0;
   
    while (i != s.size()) {
        while (i != s.size() && isspace(s[i]))
            ++i;
        
        if (i != s.size()) {
            entry.ref = &s;
            entry.position = i;
            index.push_back(entry);
        }

        while (i != s.size() && !isspace(s[i]))
            ++i;
    }
}

int main() 
{
    vector<string> sentences;
    string s;
    
    while (getline(cin, s))
        sentences.push_back(s);

    vector<Record> index;
    string::size_type maxlen = 0;

    for (vector<string>::size_type i = 0;
            i != sentences.size(); ++i) {
        add_rotations(index, sentences[i]);
        maxlen = max(maxlen, sentences[i].size());
    }

    sort(index.begin(), index.end(), compare);

    for (vector<Record>::const_iterator iter = index.begin();
            iter != index.end(); ++iter) {
        string content = *(iter->ref);
        string::size_type position = iter->position;
        cout << setw(maxlen) << content.substr(0, position) << " "
             << content.substr(position) << endl;
    }

    return 0;
}
