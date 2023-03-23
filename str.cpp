#include <iostream>
#include <cstring>
#include <memory>
#include <cctype>
#include "str.h"

using std::ostream;     using std::istream;

/*** memory management ***/
void Str::create(size_type n, char c)
{
    length = n;
    data = alloc.allocate(length + 1);
    std::uninitialized_fill(data, data + length, c);
    data[length] = 0;
}

void Str::create(const char* cp) 
{
    length = std::strlen(cp);
    data = alloc.allocate(length + 1);
    std::uninitialized_copy(cp, cp + length, data);
    data[length] = 0;
}

template<class In>
void Str::create(In b, In e)
{
    length = e - b;
    data = alloc.allocate(length + 1);
    std::uninitialized_copy(b, e, data);
    data[length] = 0;
}

void Str::uncreate()
{
    if (length) {
        for (size_type i = length - 1; i != 0; --i)
            alloc.destroy(data + i);
        alloc.deallocate(data, length);
    }
    data = 0;
}

/*** operators ***/
Str operator+(const Str& s, const Str& t)
{
    Str ret = s;
    ret += t;
    return ret;
}

Str& Str::operator=(const Str& rhs)
{
    if (this != &rhs) {
        uncreate();
        create(rhs.begin(), rhs.end());
    }
    return *this;
}

/*** friend and non-member functions ***/
ostream& operator<<(ostream& os, const Str& s)
{
    for (Str::size_type i = 0; i != s.size(); ++i)
        os << s[i];
    
    return os;
}

istream& operator>>(istream& is, Str& s)
{
    char buffer[1000];
    Str::size_type n = 0;

    char c;
    while (is.get(c) && isspace(c));

    if (is) {
        do {
            buffer[n++] = c;
        } while (is.get(c) && !isspace(c));

        if (is)
            is.unget();
    }
    
    s.data = s.alloc.allocate(n + 1);
    std::uninitialized_copy(buffer, buffer + n, s.data);
    s.data[n] = 0;
    s.length = n;

    return is;
}
