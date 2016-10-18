//
// Created by mafn on 10/17/16.
//

#ifndef MINOR_CPP1_MONSTERFILEPARSER_HPP
#define MINOR_CPP1_MONSTERFILEPARSER_HPP

#include <map>
#include <string>
#include <vector>

#include "monsters/Enemy.hpp"

namespace Monsters {
    using std::map;
    using std::string;
    using std::vector;

    typedef map<string, Enemy> MonsterMap;

    class MonsterFileParser {
    public:
        static MonsterMap parse_monsters_file(string monsters_file_path);
        static Enemy _parse_enemy(string monster_string);
    };
}


#endif //MINOR_CPP1_MONSTERFILEPARSER_HPP
