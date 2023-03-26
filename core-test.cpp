/**
 * dependencies:
 *     stats.cpp
 *     student.cpp
 *     student-utils.cpp
 *     core.cpp
 **/
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>
#include "core.h"

using std::vector;          using std::cin;
using std::cout;            using std::endl;
using std::string;          using std::max;
using std::cerr;            using std::domain_error;
using std::sort;

int main()
{
    vector<Core*> students;
    Core* student;
    char ch;
    string::size_type maxlen(0);

    while (cin >> ch) {
        student = ch == 'U'? new Core: new Grad; // allocate under[grad]
        student->read(cin);
        students.push_back(student);
        maxlen = max(maxlen, student->name().size());
    }

    sort(students.begin(), students.end(), compare_ptr);

    for (auto student: students) {
        cout << std::left << std::setw(maxlen) << student->name() << " "
             << std::right << std::fixed << std::setprecision(2);

        try {
            double grade = student->grade();
            cout << grade << endl;
        } catch (domain_error e) {
            cerr << "\033[1;35m" << e.what() << "\033[0m" << endl;
        } 
        
        delete student; // free allocated memory
    }

    return 0;
}
