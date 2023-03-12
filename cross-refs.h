#ifndef GUARD_cross_refs_h
#define GUARD_cross_refs_h

#include <vector>
#include <string>
#include <map>
#include "strsplit.h"

std::map<std::string, std::vector<int>>
    xref(std::istream&,
         std::vector<std::string>(const std::string&) = strsplit);

#endif
