#ifndef GUARD_sentence_gen_h
#define GUARD_sentence_gen_h

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

bool bracketed(const std::string&);
int nrand(int);

std::map<std::string, std::vector<std::vector<std::string>>>
    read_grammar(std::ifstream&);

template<class OutIterator>
void generate(
       const std::map<std::string, std::vector<std::vector<std::string>>>&,
       const std::string&,
       OutIterator result);

#include "sentence-gen.tpp"

#endif
