#include <cstring>
#include <memory>
#include "vec.h"

class Str {
    friend std::istream& operator>>(std::istream&, Str&);

public:
    typedef size_t size_type;

    Str();

    explicit Str(const char*);

    Str(size_type, char);
    
    template<class In> Str(In, In);

    // rule of three: copy constructor
    Str(const Str&);

    // rule of three: assignment operator
    Str& operator=(const Str&);

    // rule of three: destructor
    ~Str();

    char& operator[](size_type i) { return first[i]; }
    const char& operator[](size_type i) const { return first[i]; }

    Str& operator+=(const Str& s);

    operator bool() const { return first; }

    bool operator>(const Str&);
    bool operator<(const Str&);
    bool operator>=(const Str&);
    bool operator<=(const Str&);
    bool operator==(const Str&);

    char* begin() { return first; }
    const char* begin() const { return first; }

    char* end() { return next; }
    const char* end() const { return next; }

    size_type size() const { return next - first; }
    void copy(char* s, size_type n) const {
        std::strncpy(s, first, n);
    }

private:
    char* first;
    char* next;
    char* last;

    void resize(size_type);
    void append(const char&);
    char pop();

    std::allocator<char> alloc;
    
    void create();
    void create(size_type, char);
    void create(const char*);
    
    template<class In> void create(In b, In e);

    void uncreate();
};

std::ostream& operator<<(std::ostream&, const Str&);
Str operator+(const Str&, const Str&);
