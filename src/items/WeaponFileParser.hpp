//
// Created by mafn on 10/27/16.
//

#ifndef MINOR_CPP1_WEAPONFILEPARSER_HPP
#define MINOR_CPP1_WEAPONFILEPARSER_HPP

#include <map>
#include <vector>
#include "EquippableItem.hpp"

namespace Items {
    using std::map;
    using std::string;
    using std::vector;
    using std::stoi;

    typedef map<string, EquippableItem> WeaponMap;

    class WeaponFileParser {
    public:
        static WeaponMap parse_weapons_file(string filename);
        static EquippableItem parse_weapon(string weapon_string);
    private:

        static string _get_name(vector<string> weapon_props);
        static string _get_description(vector<string> weapon_props);
        static Damage _get_damage(vector<string> weapon_props);
    };
}


#endif //MINOR_CPP1_WEAPONFILEPARSER_HPP
