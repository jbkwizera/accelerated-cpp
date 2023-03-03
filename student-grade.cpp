// Working with batches of data
#include <iostream>
#include <string>
#include <iomanip>
#include <ios>
#include <vector>
#include <algorithm>
#include <stdexcept>

using std::cout;    using std::string;
using std::cin;     using std::streamsize;
using std::endl;    using std::setprecision;
using std::vector;  using std::sort; 
using std::istream; using std::domain_error;

istream& read_hw(istream& in, vector<double>& hw)
{
    if (in) {
        hw.clear();
        double x;
        while (in >> x)
            hw.push_back(x);
        in.clear();
    }
    return in;
}

double grade(double midterm, double final_exam, double homework)
{
    return 0.2 * midterm + 0.4 * final_exam + 0.4 * homework;
}

double median(vector<double> a)
{
    vector<double>::size_type size = a.size();
    if (size == 0)
        throw domain_error("median of an empty vector");

    sort(a.begin(), a.end());
    vector<double>::size_type mid = size/2;
    return size % 2 == 0? (a[mid] + a[mid+1])/2 : a[mid];
}

double grade(double midterm, double final_exam, const vector<double>& hw)
{
    if (hw.size() == 0)
        throw domain_error("student has done no homework");
    return grade(midterm, final_exam, median(hw));
}

int main()
{
    cout << "Please enter your first name: ";
    string name;
    cin >> name;
    cout << "Hello, " << name << "!" << endl;

    double midterm, final_exam;
    cout << "Please enter your midterm and final exam grades: ";
    cin >> midterm >> final_exam;

    cout << "Enter all your homework grades followed by EOF : ";
    vector<double> homework;
    read_hw(cin, homework);

    try {
        streamsize prec = cout.precision();
        cout << "Your final grade is " << setprecision(3)
             << grade(midterm, final_exam, homework)
             << setprecision(prec) << endl;
    } catch (domain_error) {
        cout << endl << "You must enter your grades. "
                        "Please try again." << endl;
        return 1;
    }

    return 0;
}
