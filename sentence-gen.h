#ifndef GUARD_sentence_gen_h
#define GUARD_sentence_gen_h

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

bool bracketed(const std::string&);
unsigned int get_random(unsigned int, unsigned int);

std::map<std::string, std::vector<std::vector<std::string>>>
    read_grammar(std::ifstream&);

std::vector<std::string>
    generate(
       const std::map<std::string, std::vector<std::vector<std::string>>>&,
       const std::string&);

#endif
