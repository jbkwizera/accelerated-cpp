#include <vector>
#include <string>

template<class OutIterator>
void generate(
    const std::map<std::string, std::vector<std::vector<std::string>>>& grammar,
    const std::string& category,
    OutIterator result)
{
    const std::vector<std::vector<std::string>>& rules =
        grammar.find(category)->second;
    const std::vector<std::string>& current_rule =
        rules[nrand(rules.size())];

    for (auto token: current_rule)
        if (bracketed(token))
            generate(grammar, token, result);
        else
            *result++ = token;
}
