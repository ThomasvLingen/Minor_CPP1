//
// Created by mafn on 10/28/16.
//

#include <util/StrUtil.hpp>
#include <player/PlayerFileParser.hpp>
#include "CharacterMenu.hpp"
#include "CreateCharacterState.hpp"
#include "Game.hpp"
#include "MenuState.hpp"

namespace States {

    CharacterMenu::CharacterMenu(Game::Game &game)
    : State(game)
    {

    }

    CharacterMenu::~CharacterMenu()
    {

    }

    void CharacterMenu::run()
    {
        while (this->_state_active) {
            string result = this->game.cli.ask_for_options(this->_menu);

            if (result == "create") {
                this->_create_handler();
            }
            else if (result == "list") {
                this->_list_handler();
            }
            else if(result == "select") {
                this->_select_handler();
            }
            else if (result == "remove") {
                this->_remove_handler();
            }
            else if (result == "save") {
                this->_save_handler();
            }
            else if (result == "load") {
                this->_load_handler();
            }
            else if (result == "back") {
                this->_back_handler();
            }
        }
    }

    void CharacterMenu::_create_handler()
    {
        this->game.change_state(new CreateCharacterState(this->game));
        this->_state_active = false;
    }

    void CharacterMenu::_list_handler()
    {
        this->game.players.print_players();
    }

    void CharacterMenu::_back_handler()
    {
        this->game.change_state(new MenuState(this->game));
        this->_state_active = false;
    }

    void CharacterMenu::_remove_handler()
    {
        CLI::OptionsQuestion remove_question = {
            .question = "Who do you want to remove?",
            .options = this->game.players.get_player_names()
        };

        string result = this->game.cli.ask_for_options(remove_question);
        Player::Player* to_remove = this->game.players.get_player(result);

        if (to_remove != nullptr) {
            bool is_selected_player = to_remove == this->game.players.get_selected_player();

            this->game.players.remove_player(to_remove);

            bool can_select_another_player = this->game.players.count() > 0;

            // If the deleted player was the selected one and there is another player to select
            if (is_selected_player && can_select_another_player) {
                // Select a new player
                this->_select_handler();
            } else {
                // Otherwise, set the selected player to nullptr
                this->game.players.select_player(nullptr);
            }
        }
    }

    void CharacterMenu::_select_handler()
    {
        if (this->game.players.count() > 0) {
            CLI::OptionsQuestion remove_question = {
                .question = "Who do you want to select?",
                .options = this->game.players.get_player_names()
            };

            string result = this->game.cli.ask_for_options(remove_question);
            Player::Player* to_select = this->game.players.get_player(result);

            if (to_select != nullptr) {
                this->game.players.select_player(to_select);
            }
        } else {
            cout << "It's difficult to select a character when there are none." << endl;
        }
    }

    void CharacterMenu::_save_handler()
    {
        vector<string> output_lines;

        for (Player::Player* player : this->game.players.players) {
            for (string line : player->to_string()) {
                output_lines.push_back(line);
            }

            output_lines.push_back("");
        }

        Util::StrUtil::write_lines_to_file("./saved_players", output_lines);

        cout << "Characters saved to file" << endl << endl;
    }

    void CharacterMenu::_load_handler()
    {
        // Reset old players
        this->game.players.empty();

        vector<Player::Player*> loaded_players = ::Player::PlayerFileParser::parse_players_file("./saved_players");

        for (Player::Player* player : loaded_players) {
            this->game.players.add_player(player);
        }

        cout << "Loaded players" << endl;
    }
}