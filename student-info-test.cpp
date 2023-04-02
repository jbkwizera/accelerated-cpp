/**
 * dependencies:
 *     stats.cpp
 *     student-utils.cpp
 *     core.cpp
 *     student-info.cpp
 **/
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>
#include "student-info.h"

using std::vector;          using std::cin;
using std::cout;            using std::endl;
using std::string;          using std::max;
using std::cerr;            using std::domain_error;
using std::sort;

int main()
{
    vector<StudentInfo> students;
    string::size_type maxlen(0);
    StudentInfo record;

    while (record.read(cin)) {
        students.push_back(record);
        maxlen = max(maxlen, record.name().size());
    }

    sort(students.begin(), students.end(), StudentInfo::compare);

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
