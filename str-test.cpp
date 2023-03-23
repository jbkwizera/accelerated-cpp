#include <iostream>
#include <fstream>
#include "str.h"
#include "vec.h"

using std::cout;        using std::endl;
using std::ifstream;
int main(int argc, const char* argv[])
{
    Str s("a");

    const char* sptr = s.c_str();

    s = "b";

    cout << s << endl;
    cout << sptr << endl;

    return 0;
}
