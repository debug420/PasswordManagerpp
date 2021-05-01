#pragma once
#include <iostream>
#include <ctype.h>
#include <string>
#include <vector>

namespace pm
{

    std::vector<std::string> split(const std::string& str, const std::string& delim)
    {
        std::vector<std::string> tokens;
        size_t prev = 0, pos = 0;
        do
        {
            pos = str.find(delim, prev);
            if (pos == std::string::npos) pos = str.length();
            std::string token = str.substr(prev, pos - prev);
            if (!token.empty()) tokens.push_back(token);
            prev = pos + delim.length();
        }     while (pos < str.length() && prev < str.length());
        return tokens;
    }

    std::string lowerString(std::string s)
    {
        for (int i = 0, n = s.length(); i < n; i++)
        {
            s[i] = tolower(s[i]);
        }
        return s;
    };
    
}
