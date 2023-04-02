// grade-analysis.cpp
#include <ostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include "stats.h"
#include "student-info.h"
#include "grade-analysis.h"

using std::vector;      using std::back_inserter;
using std::transform;   using std::ostream;
using std::string;      using std::endl;
using std::left;        using std::right;
using std::fixed;       using std::setprecision;
using std::setw;

void write_analysis(ostream& out, const string& name,
        double gradef(const StudentInfo&),
        const vector<StudentInfo>& did,
        const vector<StudentInfo>& didnt)
{
    out << setw(20) << left << name
        << fixed << setprecision(1) << setw(10) << tanalysis(did, gradef)
        << fixed << setprecision(1) << setw(10) << tanalysis(didnt, gradef)
        << endl;
}

/* grading schemes wrappers */
double grade_aux(const StudentInfo& s)
{   return s.grade(); }

double grade_mean_aux(const StudentInfo& s)
{   return s.grade_mean(); }

double grade_optimistic_median_aux(const StudentInfo& s)
{   return s.grade_optimistic_median(); }
