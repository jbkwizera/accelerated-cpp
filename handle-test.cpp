/**
 * dependencies:
 *     stats.cpp
 *     student-utils.cpp
 *     core.cpp
 *     core-handle.cpp !important: needs to be friends with Core 
 **/
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>
#include "core.h"
#include "core-handle.h"
#include "handle.h"

using std::vector;          using std::cin;
using std::cout;            using std::endl;
using std::string;          using std::max;
using std::cerr;            using std::domain_error;
using std::sort;

bool compare_Core_handles(
    const Handle<Core>& lhs, const Handle<Core> rhs)
{
    return lhs->name() < rhs->name();
}

int main()
{
    vector<Handle<Core>> students;
    char ch;
    string::size_type maxlen(0);

    Handle<Core> student;
    student = new Core;

    while (cin >> ch) {
        if      (ch == 'U') student = new Core;
        else if (ch == 'G') student = new Grad;
        else                student = new Credit;
        student->read(cin);
        students.push_back(student);
        maxlen = max(maxlen, student->name().size());
    }

    sort(students.begin(), students.end(), compare_Core_handles);

    for (auto student: students) {
        cout << std::left << std::setw(maxlen) << student->name() << " ";

        try {
            double grade = student->grade();
            cout << std::right << std::setw(6)
                 << std::fixed << std::setprecision(2) << grade << endl;
        } catch (domain_error e) {
            cerr << "\033[1;35m" << e.what() << "\033[0m" << endl;
        } 
    }

    return 0;
}
