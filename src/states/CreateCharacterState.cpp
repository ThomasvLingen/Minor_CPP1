//
// Created by mafn on 10/21/16.
//

#include "CreateCharacterState.hpp"
#include "MenuState.hpp"
#include <Game.hpp>

namespace States {

    CreateCharacterState::CreateCharacterState(Game::Game &game)
    : State(game)
    {

    }

    void CreateCharacterState::run()
    {
        cout << "This is the create character state, there is nothing here yet" << endl;
        cout << "We're now going back to the menu state" << endl << endl;

        this->game.change_state(new MenuState(this->game));
    }

    CreateCharacterState::~CreateCharacterState()
    {

    }
}