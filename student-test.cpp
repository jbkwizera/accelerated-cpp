/**
 * dependencies:
 *     stats.cpp
 *     core-handle.cpp
 *     student-utils.cpp
 **/
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <string>
#include "student-utils.h"
#include "core-handle.h"

using std::cout;            using std::cin;
using std::vector;          using std::endl;
using std::setprecision;    using std::setw;
using std::left;            using std::fixed;
using std::right;

int main()
{
    vector<CoreHandle> students;
    CoreHandle s;
    while (s.read(cin))
        students.push_back(s);

    vector<CoreHandle> fail = extract_fails(students);
    sort(fail.begin(), fail.end(), CoreHandle::compare_grade);

    for (auto student: fail)
        cout << "[F] " << left << setw(20) << student.name()
             << right << setw(5) << fixed << setprecision(2)
             << student.grade() << endl;

    sort(students.begin(), students.end(), CoreHandle::compare_grade);
    for (auto student: students)
        cout << "[P] " << left << setw(20) << student.name()
             << right << setw(5) << fixed << setprecision(2)
             << student.grade() << endl;

    return 0;
}
