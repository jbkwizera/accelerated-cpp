#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include "stats.h"
#include "student.h"
#include "student-utils.h"

using std::istream;         using std::accumulate;
using std::vector;          using std::remove_copy;
using std::find;            using std::back_inserter;

/*** class implementation ***/
Student::Student(): midterm(0), final_exam(0) {}

Student::Student(istream& in)
{
    read(in);
}

istream& Student::read(istream& in)
{
    in >> n >> midterm >> final_exam;
    ::read_hw(in, homework);
    total = homework.size() == 0?
            ::grade(midterm, final_exam, 0):
            ::grade(midterm, final_exam, homework);
    return in;
}

double Student::grade() const
{
    return total;
}

double Student::grade_mean() const
{
    double homework_mean = accumulate(
       homework.begin(), homework.end(), 0.0) / homework.size();

    return ::grade(midterm, final_exam, homework_mean);
}

double Student::grade_optimistic_median() const
{
    vector<double> nonzero;
    remove_copy(homework.begin(), homework.end(),
            back_inserter(nonzero), 0);

    if (nonzero.empty())
        return ::grade(midterm, final_exam, 0);

    return ::grade(midterm, final_exam, ::median(nonzero));
}

bool Student::pass() const
{
    return total >= PASS_GRADE;
}

bool Student::did_all_homework() const
{
    return (find(homework.begin(), homework.end(), 0) ==
            homework.end());
}
