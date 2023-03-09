#ifndef GUARD_strsplit_h
#define GUARD_strsplit_h

#include <string>
#include <vector>

bool space(char c);
bool not_space(char c);
std::vector<std::string> strsplit(const std::string& s);

#endif
