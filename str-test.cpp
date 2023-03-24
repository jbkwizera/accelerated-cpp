#include <iostream>
#include <fstream>
#include "str.h"
#include "vec.h"

using std::cout;        using std::endl;
using std::ifstream;

int main(int argc, const char* argv[])
{
    Str s("a");

    char sptr[s.size() + 1];
    s.copy(sptr, s.size());
    sptr[s.size()] = 0;

    s = "b";

    Str t = sptr;

    cout << s << endl;
    cout << sptr << endl;
    cout << (t + sptr + s) << endl;

    return 0;
}
