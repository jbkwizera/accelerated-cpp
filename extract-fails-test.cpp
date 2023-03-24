// extract-fails-test.cpp
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <string>
#include "student-info.h"

using std::cout;            using std::cin;
using std::vector;          using std::endl;
using std::setprecision;    using std::setw;
using std::left;            using std::fixed;

bool pgrade(const Student_info& s)
{
    return s.pass();
}

vector<Student_info> extract_fails(vector<Student_info>& students)
{
    vector<Student_info>::iterator fbegin =
        std::stable_partition(students.begin(), students.end(), pgrade);

    vector<Student_info> fail(fbegin, students.end());
    students.erase(fbegin, students.end());

    return fail;
}

int main()
{
    vector<Student_info> students;
    Student_info s;
    while (s.read(cin))
        students.push_back(s);

    vector<Student_info> fail = extract_fails(students);
    sort(fail.begin(), fail.end(), compare_grade);

    for (auto student: fail)
        cout << "[F] " << left << setw(20) << student.name()
             << fixed << setprecision(2) << student.grade() << endl;

    sort(students.begin(), students.end(), compare_grade);
    for (auto student: students)
        cout << "[P] " << left << setw(20) << student.name()
             << fixed << setprecision(2) << student.grade() << endl;

    return 0;
}
