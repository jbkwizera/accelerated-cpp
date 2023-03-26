#ifndef GUARD_student_h
#define GUARD_student_h

#include <string>
#include <vector>
#include <iostream>

class Student {
public:
    Student();
    Student(std::istream&);
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

#endif
