// grade-analysis.cpp
#include <ostream>
#include <algorithm>
#include <vector>
#include <string>
#include "student.h"
#include "stats.h"
#include "grade.h"
#include "grade-analysis.h"

using std::vector;      using std::back_inserter;
using std::transform;   using std::ostream;
using std::string;      using std::endl;

double median_analysis(const vector<Student>& students)
{
    vector<double> grades;

    transform(students.begin(), students.end(),
            back_inserter(grades), grade_aux);

    return median(grades);
}

double average_analysis(const vector<Student>& students)
{
    vector<double> grades;

    transform(students.begin(), students.end(),
            back_inserter(grades), grade_mean);

    return median(grades); 
}

double optimistic_median_analysis(const vector<Student>& students)
{
    vector<double> grades;

    transform(students.begin(), students.end(),
            back_inserter(grades), grade_optimistic_median);

    return median(grades);
}

void write_analysis(ostream& out, const string& name,
        double analysis(const vector<Student>&),
        const vector<Student>& did,
        const vector<Student>& didnt)
{
    out << name << ": median(did) = " << analysis(did) <<
                   ": median(didnt) = " << analysis(didnt) << endl;
}
