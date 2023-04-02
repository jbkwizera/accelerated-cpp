/**
 * Generic/type-independent handler for
 * memory management abstraction (pointer behavior).
 * This helps avoid the need to provide the interface
 * of whatever class the handle is dealing with.
 **/

#include <stdexcept>

template<class T> class Handle {
public:
    // constructors and copy control
    Handle(): ptr(0) {}

    Handle(const Handle& h): ptr(0) {
        if (h.ptr) ptr = h.ptr->clone();
    }

    Handle(T* t): ptr(t) {}

    Handle& operator=(const Handle& rhs) {
        if (this != &rhs) {
            delete ptr;
            ptr = rhs.ptr? rhs.ptr->clone(): 0;
        }
        return *this;
    }

    ~Handle() { delete ptr; }

    // operations
    operator bool() const {
        return ptr;
    }
    
    T& operator*() const {
        if (ptr) return *ptr;
        throw std::runtime_error("unbound Handle");
    }

    T* operator->() const {
        if (ptr) return ptr;
        throw std::runtime_error("unbound Handle");
    }

private:
    T* ptr;
};
