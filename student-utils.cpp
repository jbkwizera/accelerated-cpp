#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include "stats.h"
#include "student.h"
#include "student-utils.h"

using std::vector;      using std::stable_partition;
using std::istream;     using std::domain_error;

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

vector<Student> extract_fails(vector<Student>& students)
{
    vector<Student>::iterator fbegin =
        stable_partition(students.begin(), students.end(),
                [](const Student& s) { return s.pass(); });

    vector<Student> fail(fbegin, students.end());
    students.erase(fbegin, students.end());

    return fail;
}

bool compare(const Student& x, const Student& y)
{
    return x.name() < y.name();
}

bool compare_grade(const Student& x, const Student& y)
{
    return x.grade() < y.grade();
}
