#include <iostream>
#include <algorithm>
#include <cstring>
#include <memory>
#include <cctype>
#include "str.h"

using std::ostream;     using std::istream;

/*** constructors ***/
Str::Str()
{
    create();
}

Str::Str(const char* cp)
{
    create(cp, cp + std::strlen(cp));
}

Str::Str(size_type n, char c)
{
    create(n, c);
}

template<class In> Str::Str(In b, In e)
{
    create(b, e);
}

/* 1. rule of three: copy constructor */
Str::Str(const Str& s)
{
    create(s.begin(), s.end());
}

/* 2. rule of three: destructor */
Str::~Str()
{
    uncreate();
}

/* 3. rule of three: assignment operator */
Str& Str::operator=(const Str& rhs)
{
    if (this != &rhs) {
        uncreate();
        create(rhs.begin(), rhs.end());
    }
    return *this;
}


/*** operators ***/
Str& Str::operator+=(const Str& s)
{
    for (const char* it = s.begin(); it != s.end(); ++it)
        append(*it);

    return *this;
}

Str operator+(const Str& s, const Str& t)
{
    Str ret = s;
    ret += t;
    return ret;
}

bool Str::operator<(const Str& t)
{
    if (&t == this) return 0;

    size_type m = size();
    size_type n = t.size();

    size_type i = 0;
    size_type x = std::min(m, n);

    while (i != x && first[i] == t[i])
        ++i;

    return (i == x && n != i) || (i != x && first[i] < t[i]);
}

bool Str::operator>(const Str& t)
{
    if (&t == this) return 0;

    size_type m = size();
    size_type n = t.size();

    size_type i = 0;
    size_type x = std::min(m, n);

    while (i != x && first[i] == t[i])
        ++i;

    return (i == x && m != i) || (i != x && first[i] > t[i]);
}

bool Str::operator<=(const Str& t)
{
    if (&t == this) return 1;

    size_type m = size();
    size_type n = t.size();

    size_type i = 0;
    size_type x = std::min(m, n);

    while (i != x && first[i] == t[i])
        ++i;

    return (i == x && (n != i || m == n)) ||
           (i != x && first[i] <= t[i]);
}

bool Str::operator>=(const Str& t)
{
    if (&t == this) return 1;

    size_type m = size();
    size_type n = t.size();

    size_type i = 0;
    size_type x = std::min(m, n);

    while (i != x && first[i] == t[i])
        ++i;

    return (i == x && (m != i || m == n)) ||
           (i != x && first[i] >= t[i]);
}

bool Str::operator==(const Str& t)
{
    if (&t == this) return 1;

    size_type m = size();
    size_type n = t.size();

    size_type i = 0;
    size_type x = std::min(m, n);

    while (i != x && first[i] == t[i])
        ++i;

    return (i == x && m == n);
}

ostream& operator<<(ostream& os, const Str& s)
{
    for (Str::size_type i = 0; i != s.size(); ++i)
        os << s[i];
    
    return os;
}

istream& operator>>(istream& is, Str& s)
{
    s.uncreate();

    char c;
    while (is.get(c) && isspace(c));

    if (is) {
        do {
            s.append(c);
        } while (is.get(c) && !isspace(c));

        if (is)
            is.unget();
    }

    return is;
}

/*** private member functions ***/
void Str::resize(size_type capacity)
{
    char* first_ = alloc.allocate(capacity);
    char* next_ = std::uninitialized_copy(first, next, first_);
    uncreate();
    first = first_;
    next = next_;
    last = first + capacity;
}

void Str::append(const char& c)
{
    if (next == last)
        resize(std::max(size_type(1), 2 * size()));

    alloc.construct(next++, c);
}

char Str::pop()
{
    if (first) return 0;

    char ret = *--next;
    alloc.destroy(next);

    size_type capacity = last - first;
    size_type n = next - first;

    if (n > 0 && n == capacity/4) resize(capacity/2);

    return ret;
}

/*** memory management ***/
void Str::create()
{
    first = next = last = 0;
}

void Str::create(size_type n, char c)
{
    first = alloc.allocate(n);
    next = last = first + n;
    std::uninitialized_fill(first, first + n, c);
}

void Str::create(const char* cp) 
{
    size_type n = std::strlen(cp);
    first = alloc.allocate(n);
    next = last = std::uninitialized_copy(cp, cp + n, first);
}

template<class In> void Str::create(In b, In e)
{
    size_type n = e - b;
    first = alloc.allocate(n);
    next = last = std::uninitialized_copy(b, e, first);
}

void Str::uncreate()
{
    if (first) {
        for (char* it = last; it != first; --it)
            alloc.destroy(it);
        alloc.deallocate(first, last - first);
    }
    first = next = last = 0;
}
