//
// Created by mafn on 10/17/16.
//

#ifndef MINOR_CPP1_STRUTIL_HPP
#define MINOR_CPP1_STRUTIL_HPP

#include <vector>
#include <string>


namespace Util {
    class StrUtil {
    public:
        static std::vector<std::string> get_lines_from_file(std::string filename);
        static std::vector<std::string> split(std::string str, char delim);
    };
}


#endif //MINOR_CPP1_STRUTIL_HPP
