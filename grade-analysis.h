#ifndef GUARD_grade_analysis_h
#define GUARD_grade_analysis_h

// grade-analysis.h
#include <iostream>
#include <string>
#include <vector>
#include "core-handle.h"

void write_analysis(
    std::ostream&,
    const std::string&,
    double(const CoreHandle&),
    const std::vector<CoreHandle>&,
    const std::vector<CoreHandle>&);

template<class GraderFunction>
double analysis(const std::vector<CoreHandle>&, GraderFunction gradef);

double grade_aux(const CoreHandle&);
double grade_mean_aux(const CoreHandle&);
double grade_optimistic_median_aux(const CoreHandle&);

#include "grade-analysis.ipp"

#endif
