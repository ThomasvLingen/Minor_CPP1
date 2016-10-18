//
// Created by mafn on 10/17/16.
//

#include <algorithm>

#include "StrUtil.hpp"
#include "Enemy.hpp"
#include "MonsterFileParser.hpp"


namespace Monsters {

    // This function returns a map object (Not a pointer or reference)
    // The reason this is done because:
    // - Copying a MonsterMap is not expensive
    // - Now we don't have to either parse a map pointer as a parameter OR allocate the map on heap
    MonsterMap MonsterFileParser::parse_monsters_file(string monsters_file_path)
    {
        MonsterMap map;

        vector<string> lines = StrUtil::get_lines_from_file(monsters_file_path);
        MonsterFileParser::_filter_non_enemy_lines(lines);

        return map;
    }

//    Enemy MonsterFileParser::_parse_enemy(string monster_string)
//    {
//
//    }

    void MonsterFileParser::_filter_non_enemy_lines(vector<string>& lines)
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
            std::remove_if(lines.begin(), lines.end(),filter_monster),
            lines.end()
        );
    }
}