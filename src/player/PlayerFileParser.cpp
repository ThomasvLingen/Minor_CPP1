//
// Created by mafn on 10/28/16.
//

#include <util/FileParseUtil.hpp>
#include <util/StrUtil.hpp>
#include <items/WeaponFileParser.hpp>
#include "PlayerFileParser.hpp"

namespace Player {

    vector<Player *> PlayerFileParser::parse_players_file(string filename)
    {
        vector<Player*> loaded_players;

        vector<string> lines = Util::StrUtil::get_lines_from_file(filename);
        lines = PlayerFileParser::get_player_lines(lines);

        while (lines.size() >= 2) {
            vector<string> player = PlayerFileParser::consume_player(lines);
            Player* parsed_player = PlayerFileParser::parse_player(player);

            loaded_players.push_back(parsed_player);
        }

        return loaded_players;
    }

    Player *PlayerFileParser::parse_player(vector<string> player)
    {
        Util::FileParseUtil::remove_brackets_from_object_lines(player);
        Util::FileParseUtil::remove_brackets_from_weapon_lines(player);
        vector<string> props = Util::FileParseUtil::get_object_properties(player[0]);

        Player* parsed_player = new Player(PlayerFileParser::_get_name(props));
        parsed_player->set_stats(Stats {
            .level = PlayerFileParser::_get_level(props),
            .health = Health {
                .max_health = PlayerFileParser::_get_max_health(props),
                .current_health = PlayerFileParser::_get_current_health(props)
            },
            .exp = PlayerFileParser::_get_exp(props),
            .hit_chance = PlayerFileParser::_get_hit_chance(props),
            .hit_times = PlayerFileParser::_get_hit_times(props),
            .defence = PlayerFileParser::_get_defence(props),
        });

        // This is ugly and stupid
        if (player[1] != "") {
            Items::EquippableItem parsed_weapon = Items::WeaponFileParser::parse_weapon(player[1]);
            parsed_player->set_weapon(parsed_weapon.clone());
        }

        return parsed_player;
    }

    vector<string> PlayerFileParser::consume_player(vector<string> &lines)
    {
        vector<string> consumed_player;

        if (lines.size() >= 2) {
            vector<string>::iterator first = lines.begin();
            vector<string>::iterator last = lines.begin() + 2;

            // Copy next 2 lines
            consumed_player.insert(consumed_player.begin(), first, last);
            // Remove from original lines
            lines.erase(first, last);
        }

        return consumed_player;
    }

    vector<string> PlayerFileParser::get_player_lines(vector<string> &lines)
    {
        vector<string> player_lines;

        for (string line : lines) {
            bool is_player = Util::StrUtil::string_contains_substr(line, "[") || Util::StrUtil::string_contains_substr(line, "]");
            bool is_weapon = Util::StrUtil::string_contains_substr(line, "<") || Util::StrUtil::string_contains_substr(line, ">");

            if (is_player || is_weapon) {
                player_lines.push_back(line);
            }
        }

        return player_lines;
    }

    string PlayerFileParser::_get_name(vector<string> props)
    {
        return props[0];
    }

    int PlayerFileParser::_get_level(vector<string> props)
    {
        return stoi(props[1]);
    }

    int PlayerFileParser::_get_max_health(vector<string> props)
    {
        return stoi(props[2]);
    }

    int PlayerFileParser::_get_current_health(vector<string> props)
    {
        return stoi(props[3]);
    }

    int PlayerFileParser::_get_exp(vector<string> props)
    {
        return stoi(props[4]);
    }

    int PlayerFileParser::_get_hit_chance(vector<string> props)
    {
        return stoi(props[5]);
    }

    int PlayerFileParser::_get_hit_times(vector<string> props)
    {
        return stoi(props[6]);
    }

    int PlayerFileParser::_get_defence(vector<string> props)
    {
        return stoi(props[7]);
    }
}