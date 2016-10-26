//
// Created by mafn on 10/21/16.
//

#include <Game.hpp>
#include "MenuState.hpp"
#include "CreateCharacterState.hpp"

States::MenuState::MenuState(Game::Game &game)
: State(game)
{

}

void States::MenuState::run()
{
    while (this->_state_active) {
        string result = this->game.cli.ask_for_options(this->_menu);

        if (result == "quit") {
            this->quit_handler();
        }
        else if (result == "credits") {
            this->credits_handler();
        }
        else if (result == "create character") {
            this->create_character_handler();
        }
    }
}

States::MenuState::~MenuState()
{
}

void States::MenuState::quit_handler()
{
    this->game.quit();
    this->_state_active = false;
}

void States::MenuState::credits_handler()
{
    cout << endl << this->_credits << endl;
}

void States::MenuState::create_character_handler()
{
    this->game.change_state(new CreateCharacterState(this->game));
    this->_state_active = false;
}
