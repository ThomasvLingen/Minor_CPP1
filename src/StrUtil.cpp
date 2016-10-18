//
// Created by mafn on 10/17/16.
//

#include <fstream>
#include <iostream>
#include "StrUtil.hpp"

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
