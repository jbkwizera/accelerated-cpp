#ifndef GUARD_student_h
#define GUARD_student_h

#include <iostream>
#include <string>
#include <vector>
#include <list>

struct Student
{
    std::string name;
    double midterm, final_exam;
    std::vector<double> homework;
};

bool compare(const Student&, const Student&);
std::istream& read_student(std::istream&, Student&);
std::istream& read_hw(std::istream&, std::vector<double>&);
std::list<Student> extract_fails(std::list<Student>&);

#endif
