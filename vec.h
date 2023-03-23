#ifndef GUARD_vec_h
#define GUARD_vec_h

#include <memory>
#include <string>
#include <algorithm>

template<class T> class Vec {
public:
    typedef T* iterator;
    typedef const T* const_iterator;
    typedef size_t size_type;
    typedef T value_type;

    // constructors
    Vec() { create(); }
    explicit Vec(size_type n, const T& val = T()) { create(n, val); }

    // copy-control rule of 3: copy constructor, assign. op., destructor
    // copy constructor and assignment
    Vec(const Vec& v) { create(v.begin(), v.end()); }
    Vec& operator=(const Vec& v);

    // destructor
    ~Vec() { uncreate(); }
    
    // member functions
    bool empty() const { return !first; }
    size_type size() const { return (next - first); }
    value_type& operator[](size_type i) { return *(first + i); }
    const value_type& operator[](size_type i) const { return *(first + i); }
    
    iterator begin() { return first; }
    const iterator begin() const { return first; }

    iterator end() { return next; }
    const iterator end() const { return next; }

    void push_back(const T& val) {
        if (next == last)
            resize(std::max(2 * size(), size_type(1)));
        unchecked_append(val);
    }

    iterator erase(const iterator&);
    iterator erase(const iterator&, const iterator&);
    void clear() { uncreate(); }

    std::string tostring() const;

private:
    iterator first;
    iterator last;
    iterator next;

    // memory management
    std::allocator<T> alloc;

    void create();
    void create(size_type, const T&);
    void create(const_iterator, const_iterator);
    void uncreate();

    // changing mem. capacity
    void resize(size_type);
    void unchecked_append(const T&);
};

#include "vec.ipp"

#endif
