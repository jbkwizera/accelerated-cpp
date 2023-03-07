// median.cpp
#include <stdexcept>
#include <algorithm>
#include "stats.h"

using std::domain_error;
using std::sort;
using std::vector;

double median(vector<double> v)
{
    vector<double>::size_type size = v.size();
    if (size == 0)
        throw domain_error("median of an empty vector");

    sort(v.begin(), v.end());
    vector<double>::size_type mid = size/2;
    return size % 2 == 0? (v[mid-1] + v[mid])/2 : v[mid];
}
