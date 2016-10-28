//
// Created by mafn on 10/21/16.
//

#include <Game.hpp>
#include "MenuState.hpp"
#include "CreateCharacterState.hpp"
#include "SetDungeonDimensionsState.hpp"
#include "CharacterMenu.hpp"

namespace States {
    MenuState::MenuState(Game::Game &game)
    : State(game)
    {

    }

    void MenuState::run()
    {
        while (this->_state_active) {
            string result = this->game.cli.ask_for_options(this->_menu);

            if (result == "quit") {
                this->quit_handler();
            }
            else if (result == "set dungeon dimensions") {
                this->set_dungeon_dimensions_handler();
            }
            else if (result == "credits") {
                this->credits_handler();
            }
            else if (result == "character menu") {
                this->character_menu_handler();
            }
        }
    }

    MenuState::~MenuState()
    {
    }

    void MenuState::quit_handler()
    {
        this->game.quit();
        this->_state_active = false;
    }

    void MenuState::credits_handler()
    {
        cout << endl << this->_credits << endl;
    }

    void MenuState::set_dungeon_dimensions_handler()
    {
        this->game.change_state(new SetDungeonDimensionsState(this->game));
        this->_state_active = false;
    }

    void MenuState::character_menu_handler()
    {
        this->game.change_state(new CharacterMenu(this->game));
        this->_state_active = false;
    }
}