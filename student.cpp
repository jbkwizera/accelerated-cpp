// student.cpp
#include "student.h"

using std::istream;
using std::vector;

bool compare(const Student& x, const Student& y)
{
    return x.name < y.name;
}

istream& read_hw(istream& in, vector<double>& hw)
{
    if (in) {
        hw.clear();
        double x; 
        while (in >> x)
            hw.push_back(x);
        in.clear();
    }
    return in;
}

istream& read_student(istream& in, Student& s)
{
    in >> s.name >> s.midterm >> s.final_exam;
    read_hw(in, s.homework); // reuse read_hw code
    return in;
}
