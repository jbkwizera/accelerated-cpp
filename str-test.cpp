#include <iostream>
#include <fstream>
#include "str.h"

using std::cout;        using std::endl;
using std::ifstream;

int main(int argc, const char* argv[])
{
    Str s("abc");
    char t[] = "abc";

    Str r;

    bool x = r;
    bool y = s;

    cout << s << endl;
    cout << t << endl;
    cout << r << endl;

    return 0;
}
