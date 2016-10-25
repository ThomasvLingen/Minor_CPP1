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
        static bool vector_contains_string(std::vector<std::string> haystack, std::string needle);
        static std::string to_lower(std::string str);
        static bool is_number(std::string str);
    };
}


#endif //MINOR_CPP1_STRUTIL_HPP
