#include <sstream>

#include "split_str.hpp"

std::vector<std::string> split_str(const std::string& str, char delim)
{
    std::vector<std::string> words;
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, delim)) 
    {
        words.push_back(token);
    }
    return words;
}
