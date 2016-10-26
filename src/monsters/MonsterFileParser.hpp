//
// Created by mafn on 10/17/16.
//

#ifndef MINOR_CPP1_MONSTERFILEPARSER_HPP
#define MINOR_CPP1_MONSTERFILEPARSER_HPP

#include <map>
#include <string>
#include <vector>

#include "monsters/Enemy.hpp"
#include "util/StrUtil.hpp"

namespace Monsters {
    using std::map;
    using std::string;
    using std::vector;
    using std::stoi;
    using Util::StrUtil;

    typedef map<string, Enemy> MonsterMap;

    class MonsterFileParser {
    public:
        static MonsterMap parse_monsters_file(string monsters_file_path);
    private:
        static Enemy _parse_monster(string monster_string);
        static void _filter_non_enemy_lines(vector<string>& lines);
        static vector<string> _get_enemy_lines(vector<string>& lines);
        static void _remove_brackets_from_enemy_lines(vector<string>& lines);

        static string _get_name(vector<string> split_enemy);
        static int _get_level(vector<string> split_enemy);
        static int _get_hit_chance(vector<string> split_enemy);
        static int _get_hit_times(vector<string> split_enemy);
        static Damage _get_damage(vector<string> split_enemy);
        static int _get_defence(vector<string> split_enemy);
        static int _get_health(vector<string> split_enemy);
    };
}


#endif //MINOR_CPP1_MONSTERFILEPARSER_HPP
