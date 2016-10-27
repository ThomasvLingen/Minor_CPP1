//
// Created by mafn on 10/17/16.
//

#include <algorithm>
#include <util/FileParseUtil.hpp>

#include "util/StrUtil.hpp"
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
        lines = Util::FileParseUtil::get_object_lines(lines);

        for (string monster_string : lines) {
            Enemy parsed_enemy = MonsterFileParser::_parse_monster(monster_string);

            map.insert(MonsterMap::value_type (parsed_enemy.get_name(), parsed_enemy));
        }

        return map;
    }

    Enemy MonsterFileParser::_parse_monster(string monster_string)
    {
        vector<string> splitted_enemy = Util::FileParseUtil::get_object_properties(monster_string);

        string name = MonsterFileParser::_get_name(splitted_enemy);
        int level = MonsterFileParser::_get_level(splitted_enemy);
        int hit_chance = MonsterFileParser::_get_hit_chance(splitted_enemy);
        int hit_times = MonsterFileParser::_get_hit_times(splitted_enemy);
        Damage dmg = MonsterFileParser::_get_damage(splitted_enemy);
        int defence = MonsterFileParser::_get_defence(splitted_enemy);
        int health = MonsterFileParser::_get_health(splitted_enemy);

        return Enemy(name, level, hit_chance, hit_times, dmg, defence, health);
    }

    string MonsterFileParser::_get_name(vector<string> split_enemy)
    {
        return split_enemy[0];
    }

    int MonsterFileParser::_get_level(vector<string> split_enemy)
    {
        string level_string = split_enemy[1];

        if (level_string == "BAAS") {
            return 11;
        } else {
            return stoi(level_string);
        }
    }

    int MonsterFileParser::_get_hit_chance(vector<string> split_enemy)
    {
        vector<string> split_hit = StrUtil::split(split_enemy[2], 'x');

        return stoi(split_hit[0]);
    }

    int MonsterFileParser::_get_hit_times(vector<string> split_enemy)
    {
        vector<string> split_hit = StrUtil::split(split_enemy[2], 'x');

        return stoi(split_hit[1]);
    }

    Damage MonsterFileParser::_get_damage(vector<string> split_enemy)
    {
        vector<string> split_dmg = StrUtil::split(split_enemy[3], '-');

        Damage damage = {
            .min = stoi(split_dmg[0]),
            .max = stoi(split_dmg[1])
        };

        return damage;
    }

    int MonsterFileParser::_get_defence(vector<string> split_enemy)
    {
        return stoi(split_enemy[4]);
    }

    int MonsterFileParser::_get_health(vector<string> split_enemy)
    {
        return stoi(split_enemy[5]);
    }
}