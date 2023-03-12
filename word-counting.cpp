// word-counting.cpp: using associative containers
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>

using std::cout;        using std::cin;
using std::endl;        using std::map;
using std::string;      using std::max;

int main()
{
    map<string, int> counter;
    string s;
    string::size_type maxlen = 0;

    while (cin >> s) {
        ++counter[s];
        maxlen = max(maxlen, s.size());
    }

    for (auto pair: counter)
        cout << std::left << std::setw(maxlen)
             << pair.first << " "
             << std::right << std::setw(2) << pair.second << endl;

    return 0;
}
