#include <iostream>
#include <fstream>
#include "str.h"

using std::cout;        using std::endl;
using std::ifstream;

int main(int argc, const char* argv[])
{
    Str s("abc");
    Str t("abc");


    cout << (s <  t) << endl;

    cout << (s >  t) << endl;
    cout << (s <= t) << endl;
    cout << (s >= t) << endl;
    cout << (s == t) << endl;

    return 0;
}
