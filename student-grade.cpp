// Working with batches of data
#include <iostream>
#include <string>
#include <iomanip>
#include <ios>
#include <vector>
#include <algorithm>
#include <stdexcept>

#include "grade.h"
#include "median.h"
#include "student.h"

using std::cout;            using std::string;
using std::cin;             using std::streamsize;
using std::endl;            using std::setprecision;
using std::vector;          using std::sort;
using std::max;             using std::domain_error;

int main()
{
    vector<Student> students;
    Student record;
    string::size_type maxlen = 0;
    while (read_student(cin, record)) {
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }

    sort(students.begin(), students.end(), compare);
    for (vector<Student>::size_type i = 0; i < students.size(); i++) {
        cout << students[i].name
             << string(maxlen + 1 - students[i].name.size(), ' ');

        try {
            double final_grade = grade(students[i]);
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade << setprecision(prec);
        } catch (domain_error e) {
            cout << e.what();
        }
        cout << endl;
    }

    return 0;
}
