// student-hw-separate.cpp: separate students who did/didn't
// do all the homework assignments
#include <iostream>
#include <vector>
#include "grade-analysis.h"
#include "student.h"

using std::cout;    using std::endl;
using std::cin;     using std::vector;

int main()
{
    vector<Student> did, didnt;
    Student s;

    while (read_student(cin, s)) {
        if (did_all_homework(s))
            did.push_back(s);
        else
            didnt.push_back(s);
    }
    
    if (did.empty()) {
        cout << "No student did all the homework!" << endl;
        return 1;
    }

    if (didnt.empty()) {
        cout << "Every student did all the homework!" << endl;
        return 1;
    }

    write_analysis(cout, "median", median_analysis, did, didnt);
    write_analysis(cout, "average", average_analysis, did, didnt);
    write_analysis(cout, "median of homework turned in",
            optimistic_median_analysis, did, didnt);
    
    return 0;
}
