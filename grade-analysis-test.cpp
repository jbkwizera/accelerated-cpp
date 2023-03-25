#include <iostream>
#include <vector>
#include "grade-analysis.h"
#include "student-info.h"

using std::cout;    using std::endl;
using std::cin;     using std::vector;

int main()
{
    vector<Student_info> did, didnt;
    Student_info s;

    while (s.read(cin)) {
        if (s.did_all_homework())
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

    write_analysis(cout, "median", grade_aux, did, didnt);
    write_analysis(cout, "average", grade_mean_aux, did, didnt);
    write_analysis(cout, "optimistic", grade_optimistic_median_aux, did, didnt);

    return 0;
}
