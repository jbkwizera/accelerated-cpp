#ifndef GUARD_grade_h
#define GUARD_grade_h

// grade.h
#include <vector>
#include "student.h"

double grade(double, double, double);
double grade(double, double, const std::vector<double>&);
double grade(const Student&);
double grade_aux(const Student&);
double grade_mean(const Student&);
double grade_optimistic_median(const Student&);
bool fgrade(const Student&);

#endif
