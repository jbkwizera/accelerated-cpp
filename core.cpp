#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <numeric>
#include "student-utils.h"
#include "stats.h"
#include "core.h"

using std::string;      using std::vector;
using std::min;         using std::istream;
using std::cerr;        using std::domain_error;
using std::endl;        using std::remove_copy;
using std::find;        using std::back_inserter;
using std::accumulate;

/*** core implementation ***/
string Core::name() const
{
    return n;
}

bool Core::pass() const
{
    return grade() >= PassGrade;
}

double Core::grade() const
{
    if (homework.size() == 0)
        throw domain_error("student has done no homework");

    return total;
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
    total = homework.size() == 0?
            ::grade(midterm, final_exam, 0):
            ::grade(midterm, final_exam, homework);
    return in;
}

double Core::grade_mean() const
{
    double homework_mean = accumulate(
       homework.begin(), homework.end(), 0.0) / homework.size();

    return ::grade(midterm, final_exam, homework_mean);
}

double Core::grade_optimistic_median() const
{
    vector<double> nonzero;
    remove_copy(homework.begin(), homework.end(),
            back_inserter(nonzero), 0);

    if (nonzero.empty())
        return ::grade(midterm, final_exam, 0);

    return ::grade(midterm, final_exam, ::median(nonzero));
}

bool Core::did_all_homework() const
{
    return (find(homework.begin(), homework.end(), 0) ==
            homework.end());
}

/*** Grad implementation ***/
istream& Grad::read(istream& in)
{
    read_common(in);
    in >> thesis;
    ::read_hw(in, homework);
    total = homework.size() == 0?
            ::grade(midterm, final_exam, 0):
            ::grade(midterm, final_exam, homework);
    return in;
}

double Grad::grade() const
{
    if (homework.size() == 0)
        throw domain_error("student has done no homework");

    return min(thesis, total);
}
