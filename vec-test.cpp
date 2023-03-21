#include <iostream>
#include <string>
#include <vector>
#include "vec.h"

using std::cout;    using std::string;
using std::endl;    using std::vector;

void print_vec(Vec<int>& v)
{
    for (Vec<int>::size_type i = 0; i != v.size(); ++i)
        cout << &v[i] << endl;
}

int main(int argc, char* argv[])
{
    Vec<int> v;
    v.push_back(1);
    v.push_back(2);
    cout << v.tostring() << endl;

    Vec<int> u(v);
    cout << u.tostring() << endl;

    u.push_back(3);
    cout << u.tostring() << endl;
    
    cout << v.tostring() << endl;
    v.push_back(4);
    cout << v.tostring() << endl;
    cout << u.tostring() << endl;

    Vec<int> w = v;
    w.push_back(5);
    cout << w.tostring() << endl;
    cout << "size: " << w.size() << endl;

    Vec<int>::size_type n = 10;
    Vec<int> a(n);
    for (Vec<int>::size_type i = 0; i != n; ++i)
        a[i] = i;
    
    cout << a.tostring() << endl;

    Vec<int>::iterator it = a.erase(a.begin(), a.end());
    cout << a.tostring() << endl;

    /*
    cout << string(13, ' ') << a.tostring() << endl;
    while (!a.empty()) {
        Vec<int>::size_type r = a.size() * ((double) rand() / RAND_MAX);
        Vec<int>::iterator ret = a.erase(a.begin() + r);
        cout << "Remove at " << r << ": ";
        cout << a.tostring() << endl;
    }
    */
    return 0;
}
