#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "student.h"
#include "core.h"

using std::string;      using std::vector;
using std::min;         using std::istream;

/*** core implementation ***/
string Core::name() const
{
    return n;
}

double Core::grade() const
{
    return ::grade(midterm, final_exam, homework);
}

istream& Core::read_common(istream& in)
{
    in >> n >> midterm >> final_exam;
    return in;
}

istream& Core::read(istream& in)
{
    read_common(in);
    ::read_hw(in, homework);
    return in;
}

/*** Grad implementation ***/
istream& Grad::read(istream& in)
{
    read_common(in);
    in >> thesis;
    ::read_hw(in, homework);
    return in;
}

double Grad::grade() const
{
    return min(Core::grade(), thesis);
}

bool compare(const Core& lhs, const Core& rhs)
{
    return lhs.name() < rhs.name();
}
