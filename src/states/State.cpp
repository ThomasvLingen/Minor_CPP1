//
// Created by mafn on 10/21/16.
//
#include "State.hpp"
#include "Game.hpp"

namespace States {

    States::State::State(Game::Game &game)
    : game(game)
    {

    }

    State::~State()
    {
    }
}
