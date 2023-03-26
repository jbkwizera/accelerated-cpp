#include <algorithm>
#include <vector>
#include "core-handle.h"
#include "stats.h"

template<class GraderFunction>
double tanalysis(
    const std::vector<CoreHandle>& students,
    GraderFunction gradef)
{
    std::vector<double> grades;

    std::transform(students.begin(), students.end(),
        std::back_inserter(grades), gradef);

    return median(grades);
}
