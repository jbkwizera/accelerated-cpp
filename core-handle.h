#ifndef GUARD_core_handle_h
#define GUARD_core_handle_h

#include <iostream>
#include <stdexcept>
#include "core.h"

class CoreHandle {
public:
    // constructors and copy-control
    CoreHandle(): cp(0) {}
    CoreHandle(std::istream& in): cp(0) { read(in); }
    CoreHandle(const CoreHandle&);
    CoreHandle& operator=(const CoreHandle&);
    ~CoreHandle() { delete cp; }

    // operations
    std::istream& read(std::istream&);

    std::string name() const {
        if (cp) return cp->name();
        throw std::runtime_error("uninitialized core");
    }

    double grade() const {
        if (cp) return cp->grade();
        throw std::runtime_error("uninitialized core");
    }

    static bool compare(const CoreHandle& lhs, const CoreHandle& rhs) {
        return lhs.name() < rhs.name();
    }

private:
    Core* cp;
};

#endif
