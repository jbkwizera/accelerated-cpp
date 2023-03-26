#ifndef GUARD_student_utils_h
#define GUARD_student_utils_h

#include <iostream>
#include <vector>
#include "student.h"

double grade(double, double, double);
double grade(double, double, const std::vector<double>&);
std::istream& read_hw(std::istream&, std::vector<double>&);
bool compare(const Student&, const Student&);
bool compare_grade(const Student&, const Student&);
std::vector<Student> extract_fails(std::vector<Student>&);

#endif
