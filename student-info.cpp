#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <numeric>
#include <vector>
#include "stats.h"
#include "student-info.h"

using std::istream;         using std::vector;
using std::domain_error;    using std::accumulate;
using std::remove_copy;     using std::back_inserter;

/*** class implementation ***/
Student_info::Student_info(): midterm(0), final_exam(0) {}

Student_info::Student_info(std::istream& in)
{
    read(in);
}

istream& Student_info::read(istream& in)
{
    in >> n >> midterm >> final_exam;
    read_hw(in);
    total = homework.size() == 0?
            ::grade(midterm, final_exam, 0):
            ::grade(midterm, final_exam, homework);
    return in;
}

istream& Student_info::read_hw(istream& in)
{
    if (in) {
        homework.clear();
        double x;
        while (in >> x)
            homework.push_back(x);
        in.clear();
    }
    return in;
}

double Student_info::grade() const
{
    return total;
}

double Student_info::grade_mean() const
{
    double homework_mean = accumulate(
       homework.begin(), homework.end(), 0.0) / homework.size();

    return ::grade(midterm, final_exam, homework_mean);
}

double Student_info::grade_optimistic_median() const
{
    vector<double> nonzero;
    remove_copy(homework.begin(), homework.end(),
            back_inserter(nonzero), 0);

    if (nonzero.empty())
        return ::grade(midterm, final_exam, 0);

    return ::grade(midterm, final_exam, ::median(nonzero));
}

bool Student_info::pass() const
{
    return total >= PASS_GRADE;
}

bool Student_info::did_all_homework() const
{
    return (find(homework.begin(), homework.end(), 0) ==
            homework.end());
}

/*** external functions ***/
double grade(
    double midterm, double final_exam, double homework)
{
    return 0.2 * midterm + 0.4 * final_exam + 0.4 * homework;
}

double grade(
    double midterm, double final_exam, const vector<double>& hw)
{
    if (hw.size() == 0)
        throw domain_error("student has done no homework");
    return grade(midterm, final_exam, ::median(hw));
}

vector<Student_info> extract_fails(vector<Student_info>& students)
{
    vector<Student_info>::iterator fbegin =
        std::stable_partition(students.begin(), students.end(),
                [](const Student_info& s) { return s.pass(); });

    vector<Student_info> fail(fbegin, students.end());
    students.erase(fbegin, students.end());

    return fail;
}

bool compare(const Student_info& x, const Student_info& y)
{
    return x.name() < y.name();
}

bool compare_grade(const Student_info& x, const Student_info& y)
{
    return x.grade() < y.grade();
}
