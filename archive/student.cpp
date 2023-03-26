// student.cpp
#include <algorithm>
#include <list>
#include "student.h"
#include "grade.h"

using std::istream;     using std::vector;
using std::list;        using std::stable_partition;
using std::find;

bool compare(const Student& x, const Student& y)
{
    return x.name < y.name;
}

istream& read_hw(istream& in, vector<double>& hw)
{
    if (in) {
        hw.clear();
        double x; 
        while (in >> x)
            hw.push_back(x);
        in.clear();
    }
    return in;
}

istream& read_student(istream& in, Student& s)
{
    in >> s.name >> s.midterm >> s.final_exam;
    read_hw(in, s.homework); // reuse read_hw code
    return in;
}

list<Student> extract_fails(list<Student>& students)
{
    list<Student> fail;
    list<Student>::iterator iter = students.begin();

    while (iter != students.end()) {
        if (fgrade(*iter)) {
            fail.push_back(*iter);
            iter = students.erase(iter);
        } else
            iter++;
    }
    return fail;
}

vector<Student> extract_fails(vector<Student>& students)
{
    vector<Student>::iterator fbegin =
        stable_partition(students.begin(), students.end(), pgrade);

    vector<Student> fail(fbegin, students.end());
    students.erase(fbegin, students.end());

    return fail;
}

bool did_all_homework(const Student& s)
{
    return (find(s.homework.begin(), s.homework.end(), 0)
            == s.homework.end());
}
