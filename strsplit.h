#ifndef GUARD_strsplit_h
#define GUARD_strsplit_h

#include <string>
#include <vector>

bool space(char);
bool not_space(char);
std::vector<std::string> strsplit(const std::string&);

template<class Out>
void strsplit(const std::string&, Out);

#include "strsplit.tpp"

#endif
