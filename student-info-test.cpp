#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include "student-info.h"

using std::cout;        using std::endl;
using std::cin;         using std::vector;
using std::string;      using std::istream_iterator;
using std::copy;        using std::back_inserter;
using std::setw;        using std::left;
using std::fixed;       using std::setprecision;
using std::sort;

int main()
{
    vector<Student_info> students;
    Student_info s;

    while (s.read(cin))
        students.push_back(s);

    sort(students.begin(), students.end(), compare_grade);

    for (auto student: students)
        cout << setw(15) << left
             << student.name() << " "
             << fixed << setprecision(1) << student.grade() << endl;

    /*
    copy(istream_iterator<Student_info>(cin),
         istream_iterator<Student_info>(),
         back_inserter(students));
    */

    return 0;
}
