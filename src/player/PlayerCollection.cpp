//
// Created by mafn on 10/24/16.
//

#include <fmt/format.h>
#include <util/StrUtil.hpp>
#include "PlayerCollection.hpp"
#include "PlayerFileParser.hpp"

namespace Player {

    PlayerCollection::PlayerCollection()
    : _selected_player(nullptr)
    {

    }

    void PlayerCollection::add_player(Player *to_add)
    {
        this->players.push_back(to_add);
        // The selected player is set to the newly added player
        this->_selected_player = to_add;
    }

    PlayerCollection::~PlayerCollection()
    {
        for (Player* player : this->players) {
            delete player;
        }
    }

    void PlayerCollection::remove_player(Player *to_remove)
    {
        this->players.erase(std::remove(this->players.begin(), this->players.end(), to_remove), this->players.end());

        delete to_remove;
    }

    void PlayerCollection::select_player(Player *to_select)
    {
        this->_selected_player = to_select;
    }

    void PlayerCollection::select_player(size_t index)
    {
        this->select_player(this->players[index]);
    }

    /// You will probably want to check if this is nullptr when using this function
    /// \return
    Player *PlayerCollection::get_selected_player()
    {
        return this->_selected_player;
    }

    void PlayerCollection::print_players()
    {
        cout << "Heros:" << endl;
        for (auto player : this->players) {
            bool is_selected_hero = player == this->_selected_player;
            string prepend = is_selected_hero ? "  * " : "    ";

            cout << prepend << player->get_name() << endl;
        }
    }

    vector<string> PlayerCollection::get_player_names()
    {
        vector<string> names;

        for (auto player : this->players) {
            names.push_back(player->get_name());
        }

        return names;
    }

    Player *PlayerCollection::get_player(string name)
    {
        for (auto player : this->players) {
            if (Util::StrUtil::to_lower(player->get_name()) == name) {
                return player;
            }
        }

        return nullptr;
    }

    size_t PlayerCollection::count()
    {
        return this->players.size();
    }

    void PlayerCollection::empty()
    {
        for (Player* player : this->players) {
            this->remove_player(player);
        }
    }

    void PlayerCollection::save_players()
    {
        vector<string> output_lines;

        for (Player* player : this->players) {
            for (string line : player->to_string()) {
                output_lines.push_back(line);
            }

            output_lines.push_back("");
        }

        Util::StrUtil::write_lines_to_file("./saved_players", output_lines);
    }

    void PlayerCollection::load_players()
    {
        // Reset old players
        this->empty();

        vector<Player*> loaded_players = PlayerFileParser::parse_players_file("./saved_players");

        for (Player* player : loaded_players) {
            this->add_player(player);
        }
    }
}
