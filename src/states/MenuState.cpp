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
            this->game.quit();
            this->_state_active = false;
        }
        else if (result == "credits") {
            cout << endl << this->_credits << endl;
        }
        else if (result == "create character") {
            this->game.change_state(new CreateCharacterState(this->game));
            this->_state_active = false;
        }
    }
}

States::MenuState::~MenuState()
{
}
