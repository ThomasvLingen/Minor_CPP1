//
// Created by mafn on 10/21/16.
//

#include <util/StrUtil.hpp>
#include <states/MenuState.hpp>
#include "Game.hpp"

namespace Game {

    Game::Game()
    {
        this->_current_state = new States::MenuState(*this);
        this->_old_state = nullptr;
    }

    Game::~Game()
    {
        delete this->_current_state;
    }

    void Game::run()
    {
        while(this->_running) {
            this->_current_state->run();
            this->delete_old_state();
        }
    }

    void Game::change_state(States::State *state)
    {
        this->_old_state = this->_current_state;

        this->_current_state = state;
    }

    void Game::delete_old_state()
    {
        if (this->_old_state != nullptr) {
            delete this->_old_state;
        }

        this->_old_state = nullptr;
    }

    void Game::quit()
    {
        this->_running = false;
    }
}