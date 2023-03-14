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

#include "grade-analysis.tpp"

#endif
