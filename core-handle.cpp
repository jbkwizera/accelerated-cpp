#include <iostream>
#include "core-handle.h"
#include "core.h"

using std::istream;

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

    if (chr == 'U') cp = new Core(in);
    else            cp = new Grad(in);

    return in;
}
