//
// Created by mafn on 10/17/16.
//

#include <fstream>
#include <iostream>
#include <algorithm>
#include "StrUtil.hpp"

namespace Util {
    std::vector<std::string> StrUtil::get_lines_from_file(std::string filename)
    {
        std::vector<std::string> lines;
        std::string line;
        std::ifstream file(filename, std::ifstream::in);

        if (file.is_open()) {
            while(std::getline(file, line)) {
                lines.push_back(line);
            }
        } else {
            std::cout << "For some reason, " << filename << " could not be opened" << std::endl;
        }

        return lines;
    }

    void StrUtil::write_lines_to_file(std::string filename, std::vector<std::string> lines)
    {
        std::ofstream output_file(filename);

        if (output_file.is_open()) {
            for (std::string& line : lines) {
                output_file << line << std::endl;
            }
        } else {
            std::cout << "For some reason, " << filename << " could not be opened" << std::endl;
        }

        output_file.close();
    };


    std::vector<std::string> StrUtil::split(std::string str, char delim) {
        std::string copy = str;
        std::vector<std::string> tokens;

        size_t delimPosition = 0;

        while(copy.find(delim) != std::string::npos || delimPosition != std::string::npos){
            delimPosition = copy.find(delim);

            std::string token = copy.substr(0, delimPosition);
            // Check if the token isn't empty, if not, push it!
            if(!token.empty()){
                tokens.push_back(token);
            }

            // Substract added token from our string
            copy = copy.substr(delimPosition + 1);
        }

        return tokens;
    }

    bool StrUtil::vector_contains_string(std::vector<std::string> haystack, std::string needle)
    {
        std::string needle_lowercase = StrUtil::to_lower(needle);

        for (std::string str : haystack) {
            if (StrUtil::to_lower(str) == needle_lowercase) {
                return true;
            }
        }

        return false;
    }

    std::string StrUtil::to_lower(std::string str)
    {
        std::transform(str.begin(), str.end(), str.begin(), tolower);

        return str;
    }

    bool StrUtil::is_number(std::string str)
    {
        if (str.empty()) {
            return false;
        }

        // This finds the first non-digit character
        auto first_non_digit_char = std::find_if(
            str.begin(),
            str.end(),
            [](char c) {
                return !std::isdigit(c);
            }
        );

        // If this is equal to the end, there isn't a non-digit char
        return first_non_digit_char == str.end();
    }

    bool StrUtil::string_contains_substr(std::string haystack, std::string needle)
    {
        return haystack.find(needle) != std::string::npos;
    }
}

