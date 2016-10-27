//
// Created by mafn on 10/27/16.
//

#include <util/StrUtil.hpp>
#include <util/FileParseUtil.hpp>
#include "WeaponFileParser.hpp"

namespace Items {

    WeaponMap WeaponFileParser::parse_weapons_file(string filename)
    {
        WeaponMap map;

        vector<string> lines = Util::StrUtil::get_lines_from_file(filename);
        lines = Util::FileParseUtil::get_object_lines(lines);

        for (string weapon_string : lines) {
            EquippableItem parsed_weapon = WeaponFileParser::_parse_weapon(weapon_string);

            map.insert(WeaponMap::value_type(parsed_weapon.get_name(), parsed_weapon));
        }

        return map;
    }

    EquippableItem WeaponFileParser::_parse_weapon(string weapon_string)
    {
        vector<string> weapon_properties = Util::FileParseUtil::get_object_properties(weapon_string);

        string name = WeaponFileParser::_get_name(weapon_properties);
        string description = WeaponFileParser::_get_description(weapon_properties);
        Damage damage = WeaponFileParser::_get_damage(weapon_properties);

        return EquippableItem(name, description, damage);
    }

    string WeaponFileParser::_get_name(vector<string> weapon_props)
    {
        return weapon_props[0];
    }

    string WeaponFileParser::_get_description(vector<string> weapon_props)
    {
        return weapon_props[1];
    }

    Damage WeaponFileParser::_get_damage(vector<string> weapon_props)
    {
        string damage_string = weapon_props[2];
        vector<string> split_damage = Util::StrUtil::split(damage_string, '-');

        Damage damage = {
            .min = stoi(split_damage[0]),
            .max = stoi(split_damage[1])
        };

        return damage;
    }


}