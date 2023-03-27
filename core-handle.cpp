#include <iostream>
#include <stdexcept>
#include <string>
#include "core-handle.h"
#include "core.h"

using std::istream;     using std::runtime_error;
using std::string;

CoreHandle::CoreHandle(const CoreHandle& ch): cp(0)
{
    if (ch.cp) cp = ch.cp->clone();
}

CoreHandle& CoreHandle::operator=(const CoreHandle& rhs)
{
    if (this != &rhs) {
        delete cp;
        cp = rhs.cp? rhs.cp->clone(): 0;
    }
    return *this;
}

istream& CoreHandle::read(istream& in)
{
    delete cp;
    char chr;

    in >> chr;

    if      (chr == 'U') cp = new Core(in);
    else if (chr == 'G') cp = new Grad(in);
    else                 cp = new Credit(in);

    return in;
}
