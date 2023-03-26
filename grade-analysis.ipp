#include <algorithm>
#include <vector>
#include "student.h"
#include "stats.h"

template<class GraderFunction>
double tanalysis(
    const std::vector<Student>& students,
    GraderFunction gradef)
{
    std::vector<double> grades;

    std::transform(students.begin(), students.end(),
        std::back_inserter(grades), gradef);

    return median(grades);
}
