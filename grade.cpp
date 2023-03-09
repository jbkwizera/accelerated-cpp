// grade.cpp
#include <algorithm>
#include <stdexcept>
#include <numeric>
#include "stats.h"
#include "grade.h"
#include "student.h"

using std::vector;
using std::domain_error;
using std::accumulate;
using std::remove_copy;

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

bool pgrade(const Student& s)
{
    return !fgrade(s);
}

double grade_aux(const Student& s)
{
    try {
        return grade(s);
    } catch(domain_error) {
        return grade(s.midterm, s.final_exam, 0);
    }
}

double grade_optimistic_median(const Student& s)
{
    vector<double> nonzero;
    remove_copy(s.homework.begin(), s.homework.end(),
            back_inserter(nonzero), 0);

    if (nonzero.empty())
        return grade(s.midterm, s.final_exam, 0);

    return grade(s.midterm, s.final_exam, median(nonzero));
}

double grade_mean(const Student& s)
{
    double homework = accumulate(s.homework.begin(),
            s.homework.end(), 0.0) / s.homework.size();

    return grade(s.midterm, s.final_exam, homework);
}
