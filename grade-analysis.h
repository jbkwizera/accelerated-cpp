#ifndef GUARD_grade_analysis_h
#define GUARD_grade_analysis_h

// grade-analysis.h
#include <iostream>
#include <string>
#include <vector>
#include "student.h"

void write_analysis(std::ostream&,
                    const std::string&,
                    double(const std::vector<Student>&),
                    const std::vector<Student>&,
                    const std::vector<Student>&);

double median_analysis(const std::vector<Student>&);
double average_analysis(const std::vector<Student>&);
double optimistic_median_analysis(const std::vector<Student>&);

#endif
