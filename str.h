#include <memory>
#include "vec.h"

class Str {
    friend std::istream& operator>>(std::istream&, Str&);

public:
    typedef size_t size_type;

    Str(): data(0), length(0) {}

    Str(size_type n, char c) { create(n, c); }
    
    Str(const char* cp) { create(cp); }

    template<class In>
    Str(In b, In e) { create(b, e); }

    // rule of three: copy constructor
    Str(const Str& s) { create(s.begin(), s.end()); }

    // rule of three: assignment operator
    Str& operator=(const Str&);

    // rule of three: destructor
    ~Str() { uncreate(); }

    char& operator[](size_type i) { return data[i]; }
    const char& operator[](size_type i) const { return data[i]; }

    Str& operator+=(const Str& s) {
        create(s.begin(), s.end());
        return *this;
    }

    operator const char*() const { return data; }

    char* begin() { return data; }
    const char* begin() const { return data; }

    char* end() { return data + length; }
    const char* end() const { return data + length; }

    size_type size() const { return length; }
    const char* c_str() const { return data; }

private:
    char* data;
    size_type length;

    std::allocator<char> alloc;
    
    void create(size_type, char);
    void create(const char*);
    
    template<class In>
    void create(In b, In e);

    void uncreate();
    void uncreate(char*);
};

std::ostream& operator<<(std::ostream&, const Str&);
Str operator+(const Str&, const Str&);
