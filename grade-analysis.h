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
    double(const StudentInfo&),
    const std::vector<StudentInfo>&,
    const std::vector<StudentInfo>&);

template<class GraderFunction>
double analysis(const std::vector<StudentInfo>&, GraderFunction gradef);

double grade_aux(const StudentInfo&);
double grade_mean_aux(const StudentInfo&);
double grade_optimistic_median_aux(const StudentInfo&);

#include "grade-analysis.ipp"

#endif
