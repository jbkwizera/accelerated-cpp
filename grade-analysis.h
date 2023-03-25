#ifndef GUARD_grade_analysis_h
#define GUARD_grade_analysis_h

// grade-analysis.h
#include <iostream>
#include <string>
#include <vector>
#include "student-info.h"

void write_analysis(
    std::ostream&,
    const std::string&,
    double(const Student_info&),
    const std::vector<Student_info>&,
    const std::vector<Student_info>&);

template<class GraderFunction>
double analysis(const std::vector<Student_info>&, GraderFunction gradef);

double grade_aux(const Student_info&);
double grade_mean_aux(const Student_info&);
double grade_optimistic_median_aux(const Student_info&);

#include "grade-analysis.ipp"

#endif
