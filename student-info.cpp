#include <iostream>
#include <vector>
#include "grade.h"
#include "student-info.h"

using std::istream;     using std::vector;

Student_info::Student_info(): midterm(0), final_exam(0) {}

Student_info::Student_info(std::istream& in)
{
    read(in);
}

istream& Student_info::read(istream& in)
{
    in >> n >> midterm >> final_exam;
    read_hw(in, homework);
    total = ::grade(midterm, final_exam, homework);
    return in;
}

double Student_info::grade() const
{
    return total;
}

bool compare(const Student_info& x, const Student_info& y)
{
    return x.name() < y.name();
}

bool compare_grade(const Student_info& x, const Student_info& y)
{
    return x.grade() < y.grade();
}
