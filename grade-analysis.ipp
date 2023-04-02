#include <algorithm>
#include <vector>
#include "student-info.h"
#include "stats.h"

template<class GraderFunction>
double tanalysis(
    const std::vector<StudentInfo>& students,
    GraderFunction gradef)
{
    std::vector<double> grades;

    std::transform(students.begin(), students.end(),
        std::back_inserter(grades), gradef);

    return median(grades);
}
