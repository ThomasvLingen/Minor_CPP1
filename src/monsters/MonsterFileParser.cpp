//
// Created by mafn on 10/17/16.
//

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

        return map;
    }

    Enemy MonsterFileParser::_parse_enemy(string monster_string)
    {

    }
}