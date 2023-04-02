#include <iostream>
#include "student-info.h"

std::istream& StudentInfo::read(std::istream& in)
{
    char ch = 0; // avoid valgrind's "conditional jump
    in >> ch;    // or move depends on uninitialized value(s)"

    if      (ch == 'U') h = new Core(in);
    else if (ch == 'G') h = new Grad(in);
    else                h = new Credit(in);

    return in;
}
