//
// Created by mafn on 10/17/16.
//

#include <fstream>
#include <iostream>
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
    };
}
