#ifndef GUARD_grade_analysis_h
#define GUARD_grade_analysis_h

// grade-analysis.h
#include <iostream>
#include <string>
#include <vector>
#include "student.h"

void write_analysis(
    std::ostream&,
    const std::string&,
    double(const Student&),
    const std::vector<Student>&,
    const std::vector<Student>&);

template<class GraderFunction>
double analysis(const std::vector<Student>&, GraderFunction gradef);

double grade_aux(const Student&);
double grade_mean_aux(const Student&);
double grade_optimistic_median_aux(const Student&);

#include "grade-analysis.ipp"

#endif
