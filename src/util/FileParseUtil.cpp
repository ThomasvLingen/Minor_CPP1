//
// Created by mafn on 10/27/16.
//

#include <algorithm>
#include "FileParseUtil.hpp"
#include "StrUtil.hpp"

namespace Util {

    /// \brief An object is defined as "[prop;prop]" with a varying amount of properties
    /// \param lines line to filter
    void FileParseUtil::filter_non_object_lines(vector<string> &lines)
    {
        auto filter_monster = [] (string str) {
            if (str.size() > 0) {
                bool has_open_bracket = str.find('[') == 0;
                bool has_closing_bracket = str.find(']') != string::npos;

                return !has_open_bracket || !has_closing_bracket;
            } else {
                return true;
            }
        };

        lines.erase(
            std::remove_if(lines.begin(), lines.end(), filter_monster),
            lines.end()
        );
    }

    void FileParseUtil::remove_brackets_from_object_lines(vector<string> &lines)
    {
        for (string& line : lines) {
            line.erase(
                std::remove(line.begin(), line.end(), '['),
                line.end()
            );

            line.erase(
                std::remove(line.begin(), line.end(), ']'),
                line.end()
            );
        }
    }

    void FileParseUtil::remove_brackets_from_weapon_lines(vector<string> &lines)
    {
        for (string& line : lines) {
            line.erase(
                std::remove(line.begin(), line.end(), '<'),
                line.end()
            );

            line.erase(
                std::remove(line.begin(), line.end(), '>'),
                line.end()
            );
        }
    }

    vector<string> FileParseUtil::get_object_lines(vector<string> &lines)
    {
        vector<string> enemy_lines;

        Util::FileParseUtil::filter_non_object_lines(lines);

        for (string line : lines) {
            size_t start_index = line.find('[');
            size_t end_index = line.find(']');

            enemy_lines.push_back(line.substr(start_index, end_index-start_index+1));
        }

        Util::FileParseUtil::remove_brackets_from_object_lines(enemy_lines);

        return enemy_lines;
    }

    vector<string> FileParseUtil::get_object_properties(string object_string)
    {
        return StrUtil::split(object_string, ';');
    }
}