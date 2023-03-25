#ifndef GUARD_student_info_h
#define GUARD_student_info_h

#include <string>
#include <vector>
#include <iostream>

class Student_info {
public:
    Student_info();
    Student_info(std::istream&);
    std::istream& read(std::istream&);
    std::string name() const { return n; }
    bool valid() const { return !homework.empty(); }
    double grade() const;
    double grade_mean() const;
    double grade_optimistic_median() const;
    bool did_all_homework() const;
    bool pass() const;

protected:
    double midterm, final_exam, total;
    std::vector<double> homework;

private:
    std::string n;
    static const int PASS_GRADE = 60;
};

double grade(double, double, double);
double grade(double, double, const std::vector<double>&);
std::istream& read_hw(std::istream&, std::vector<double>&);
bool compare(const Student_info&, const Student_info&);
bool compare_grade(const Student_info&, const Student_info&);
std::vector<Student_info> extract_fails(std::vector<Student_info>&);

#endif
