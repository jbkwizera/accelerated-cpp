#include <string>
#include <algorithm>

template <class Out>
void strsplit(const std::string& s, Out os) 
{
    std::string::const_iterator i = s.begin();
        
    while (i != s.end()) {
        i = std::find_if(i, s.end(), not_space);

        std::string::const_iterator j =
            std::find_if(i, s.end(), space);

        if (i != s.end())
            *os++ = std::string(i, j); 
        i = j;
    }   
}
