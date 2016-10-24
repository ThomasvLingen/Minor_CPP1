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
    while (true) {
        string result = this->game.ask_user_for_options(this->menu);

        if (result == "quit") {
            this->game.running = false;
            return;
        }
        else if (result == "credits") {
            cout << endl << this->credits << endl;
        }
        else if (result == "create character") {
            this->game.change_state(new CreateCharacterState(this->game));
            return;
        }
    }
}

States::MenuState::~MenuState()
{
}
