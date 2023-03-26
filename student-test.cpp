#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <string>
#include "student.h"
#include "student-utils.h"

using std::cout;            using std::cin;
using std::vector;          using std::endl;
using std::setprecision;    using std::setw;
using std::left;            using std::fixed;

int main()
{
    vector<Student> students;
    Student s;
    while (s.read(cin))
        students.push_back(s);

    vector<Student> fail = extract_fails(students);
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
