#include "StringUtils.h"

std::string StringUtils::trim(const std::string &s)
{
    size_t start = s.find_first_not_of(" \t\n\r\f\v\"");
    size_t end = s.find_last_not_of(" \t\n\r\f\v\"");
    return s.substr(start, end - start + 1);
    // TODO
}

std::vector<std::string> StringUtils::split(const std::string &s, char delimiter)
{  
    std::vector<std::string> tokens;
    std::istringstream stream(s);
    std::string token;
    while(getline(stream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
    // TODO
}

std::map<std::string, std::string> StringUtils::parseJSON(const std::string &json)
{
    map<std::string, std::string> result;
    size_t end = json.find('}');
    std::string body = json.substr(1, end - 1); 
    std::vector<std::string> pairs = split(body, ',');
    for(std::string pair : pairs)
    {
        size_t colonPos = pair.find(':');
        
        std::string key = trim(pair.substr(0, colonPos));
        std::string value = trim(pair.substr(colonPos + 1));
        if(!key.empty() && !value.empty())
        {
            result[key] = value;
        }
        
    }
    return result;
    
    // TODO
}
