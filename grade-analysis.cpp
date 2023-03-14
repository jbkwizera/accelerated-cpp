// grade-analysis.cpp
#include <ostream>
#include <iomanip>
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
using std::left;        using std::right;
using std::fixed;       using std::setprecision;
using std::setw;

void write_analysis(ostream& out, const string& name,
        double gradef(const Student&),
        const vector<Student>& did,
        const vector<Student>& didnt)
{
    out << setw(20) << left << name
        << fixed << setprecision(1) << setw(10) << tanalysis(did, gradef)
        << fixed << setprecision(1) << setw(10) << tanalysis(didnt, gradef)
        << endl;
}
