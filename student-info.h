#ifndef GUARD_student_info_h
#define GUARD_student_info_h

#include <string>
#include <vector>
#include <iostream>

class Student_info {
public:
    Student_info();
    Student_info(std::istream&);
    double grade() const;
    std::istream& read(std::istream&);
    std::string name() const { return n; }
    bool valid() const { return !homework.empty(); }

private:
    std::string n;
    double midterm, final_exam, total;
    std::vector<double> homework;
    std::istream& read_hw(std::istream& in);
};

bool compare(const Student_info&, const Student_info&);
bool compare_grade(const Student_info&, const Student_info&);

#endif
