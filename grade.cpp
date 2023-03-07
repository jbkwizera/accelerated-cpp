// grade.cpp
#include <stdexcept>

#include "grade.h"
#include "stats.h"
#include "student.h"

using std::vector;
using std::domain_error;

double grade(double midterm, double final_exam, double homework)
{
    return 0.2 * midterm + 0.4 * final_exam + 0.4 * homework;
}

double grade(double midterm, double final_exam, const vector<double>& hw) 
{
    if (hw.size() == 0)
        throw domain_error("student has done no homework");
    return grade(midterm, final_exam, median(hw));
}

double grade(const Student& s)
{
    return grade(s.midterm, s.final_exam, s.homework);
}

bool fgrade(const Student& s)
{
    return grade(s) < 60;
}

double grade_aux(const Student& s)
{
    try {
        return grade(s);
    } catch(domain_error) {
        return grade(s.midterm, s.final_exam, 0);
    }
}
