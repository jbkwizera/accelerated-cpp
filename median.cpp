// median.cpp
#include <stdexcept>
#include <algorithm>
#include "median.h"

using std::domain_error;
using std::sort;
using std::vector;

double median(vector<double> a)
{
    vector<double>::size_type size = a.size();
    if (size == 0)
        throw domain_error("median of an empty vector");

    sort(a.begin(), a.end());
    vector<double>::size_type mid = size/2;
    return size % 2 == 0? (a[mid-1] + a[mid])/2 : a[mid];
}
