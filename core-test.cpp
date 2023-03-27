/**
 * dependencies:
 *     stats.cpp
 *     student-utils.cpp
 *     core.cpp
 *     core-handle.cpp
 **/
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>
#include "core-handle.h"

using std::vector;          using std::cin;
using std::cout;            using std::endl;
using std::string;          using std::max;
using std::cerr;            using std::domain_error;
using std::sort;

int main()
{
    vector<CoreHandle> students;
    CoreHandle student;
    string::size_type maxlen(0);

    while (student.read(cin)) {
        students.push_back(student);
        maxlen = max(maxlen, student.name().size());
    }

    sort(students.begin(), students.end(), CoreHandle::compare);

    for (auto student: students) {
        cout << std::left << std::setw(maxlen) << student.name() << " ";

        try {
            double grade = student.grade();
            cout << std::right << std::setw(6)
                 << std::fixed << std::setprecision(2) << grade << endl;
        } catch (domain_error e) {
            cerr << "\033[1;35m" << e.what() << "\033[0m" << endl;
        } 
    }

    return 0;
}
