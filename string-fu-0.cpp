// Working with strings
#include <iostream>
#include <string>

int main()
{
    // Input stream
    std::cout << "Please enter your first name: ";
    std::string name;
    std::cin >> name;
    std::cout << "Hello, " + name + "!" << std::endl; 
    
    // Scope
    {
        const std::string s = "outer";
        std::cout << "outer string: " + s << std::endl;
        {
            const std::string s = "inner";
            std::cout << "inner string: " + s << std::endl;
        }
        std::cout << "outer string: " + s << std::endl;
    }

    // More on scopes
    {
        std::string s = "a string";
        {
            std::string x = s + ", really";
            std::cout << s << std::endl;
        }
        // std::cout << x << std::endl;   // var. x isn't visible in this scope
    }

    return 0;
}
