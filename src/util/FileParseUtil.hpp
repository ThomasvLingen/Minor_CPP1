//
// Created by mafn on 10/27/16.
//

#ifndef MINOR_CPP1_FILEPARSEUTIL_HPP
#define MINOR_CPP1_FILEPARSEUTIL_HPP

#include <string>
#include <vector>

namespace Util {
    using std::string;
    using std::vector;

    class FileParseUtil {
    public:
        static void filter_non_object_lines(vector<string>& lines);
        static void remove_brackets_from_object_lines(vector<string>& lines);
        static void remove_brackets_from_weapon_lines(vector<string>& lines);
        static vector<string> get_object_lines(vector<string>& lines);
        static vector<string> get_object_properties(string object_string);
    private:
    };
};


#endif //MINOR_CPP1_FILEPARSEUTIL_HPP
