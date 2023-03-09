// extract-fails-test.cpp
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include "student.h"
#include "grade.h"

using std::cout;            using std::cin;
using std::vector;          using std::endl;
using std::setprecision;    using std::setw;
using std::left;            using std::fixed;

int main()
{
    vector<Student> students;
    Student s;
    while (read_student(cin, s))
        students.push_back(s);

    vector<Student> fail = extract_fails(students);
    for (auto student: fail)
        cout << "[F] " << left << setw(20) << student.name
             << fixed << setprecision(2) << grade(student) << endl;

    for (auto student: students)
        cout << "[P] " << left << setw(20) << student.name
             << fixed << setprecision(2) << grade(student) << endl;

    return 0;
}
