// Working with batches of data
#include <iostream>
#include <string>
#include <iomanip>
#include <ios>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <list>
#include "stats.h"
#include "student.h"

using std::cout;            using std::string;
using std::cin;             using std::streamsize;
using std::endl;            using std::setprecision;
using std::vector;          using std::sort;
using std::max;             using std::domain_error;
using std::list;

int main()
{
    list<Student> students;
    Student s;
    string::size_type maxlen = 0;
    while (s.read(cin)) {
        maxlen = max(maxlen, s.name().size());
        students.push_back(s);
    }

    students.sort(compare);
    for (auto student: students) {
        cout << student.name()
             << string(maxlen + 1 - (student.name()).size(), ' ');

        try {
            double final_grade = student.grade();
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade << setprecision(prec);
        } catch (domain_error e) {
            cout << e.what();
        }
        cout << endl;
    }

    return 0;
}
