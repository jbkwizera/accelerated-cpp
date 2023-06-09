#ifndef GUARD_student_utils_h
#define GUARD_student_utils_h

#include <iostream>
#include <vector>
#include "student-info.h"

double grade(double, double, double);
double grade(double, double, const std::vector<double>&);
std::istream& read_hw(std::istream&, std::vector<double>&);
std::vector<StudentInfo> extract_fails(std::vector<StudentInfo>&);

#endif
