#ifndef GUARD_student_info_h
#define GUARD_student_info_h

/**
 * Interface to polymorphism (core and derived classes)
 * using a handle to manage memory
 **/

#include <iostream>
#include <stdexcept>
#include "core.h"
#include "handle.h"

class StudentInfo {
public:
    // constructors. copy-control not needed, handle
    // takes care of that.
    StudentInfo() {}
    StudentInfo(std::istream& in) { read(in); }

    // operations
    std::istream& read(std::istream&);

    std::string name() const {
        if (h) return h->name();
        throw std::runtime_error("uninitialized Student");
    }

    bool pass() const {
        if (h) return h->pass();
        throw std::runtime_error("uninitialized Student");
    }

    double grade() const {
        if (h) return h->grade();
        throw std::runtime_error("uninitialized Student");
    }

    double grade_mean() const {
        if (h) return h->grade_mean();
        throw std::runtime_error("uninitialized Student");
    }

    double grade_optimistic_median() const {
        if (h) return h->grade_optimistic_median();
        throw std::runtime_error("uninitialized Student");
    }

    bool did_all_homework() const {
        if (h) return h->did_all_homework();
        throw std::runtime_error("uninitialized Student");
    }

    static bool compare(
        const StudentInfo& s1, const StudentInfo& s2) {
        return s1.name() < s2.name();
    }

    static bool compare_grade(
        const StudentInfo& s1, const StudentInfo& s2) {
        return s1.grade() < s2.grade();
    }

private:
    Handle<Core> h;
};

#endif
