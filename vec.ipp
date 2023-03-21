#include <memory>
#include <sstream>
#include <string>
#include <iostream>

template<class T>
Vec<T>& Vec<T>::operator=(const Vec& rhs)
{
    if (&rhs != this) {
        // free and then populate the lhs object
        uncreate();
        create(rhs.begin(), rhs.end());
    }
    return *this;
}

template<class T>
void Vec<T>::create()
{
    first = next = last = 0;
}

template<class T>
void Vec<T>::create(size_type n, const T& val)
{
    first = alloc.allocate(n);
    next = last = first + n;
    std::uninitialized_fill(first, last, val);
}

template<class T>
void Vec<T>::create(const_iterator i, const_iterator j)
{
    first = alloc.allocate(j - i);
    next = last = std::uninitialized_copy(i, j, first);
}

template<class T>
void Vec<T>::uncreate()
{
    if (first) {
        for (iterator it = last; it != first; --it)
            alloc.destroy(it);

        alloc.deallocate(first, last - first);
    }

    first = next = last = 0;
}

template<class T>
void Vec<T>::resize(size_type capacity)
{
    iterator first_ = alloc.allocate(capacity);
    iterator next_ = std::uninitialized_copy(first, next, first_);
    uncreate();
    first = first_;
    next = next_;
    last = first + capacity;
}

template<class T>
void Vec<T>::unchecked_append(const T& val)
{
    alloc.construct(next++, val);
}

template<class T>
typename Vec<T>::iterator Vec<T>::erase(const iterator& i)
{
    if (i < first || i >= next)
        return next;
    
    iterator it = first;
    while (it != next && it != i)
        ++it;

    iterator ret = it;
    while (it != next) {
        *it = *(it + 1);
        ++it;
    }

    alloc.destroy(--next);

    if (first >= next)
       first = next = 0;

    return ret;
}

template<class T>
typename Vec<T>::iterator Vec<T>::erase(
   const iterator& i, const iterator& j) 
{
    if (i >= j || i < first || j > next)
        return next;

    for (size_type d = 0; d != next - j; ++d)
        *(i + d) = *(j + d);

    iterator next_ = i + (next - j);
    while (next != next_)
        alloc.destroy(--next);

    if (first >= next)
        first = next = 0;

    return next;
}

template<class T>
std::string Vec<T>::tostring() const
{
    if (!first) return std::string("");

    std::stringstream ret;
    ret << *first;

    for (iterator it = first+1; it < next; ++it)
        ret << " " << *it;
    
    return ret.str();
}
