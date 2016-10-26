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
        if (this->_current_state != nullptr) {
            delete this->_current_state;
        }
    }

    string Game::ask_user_for_options(CLI::OptionsQuestion prompt)
    {
        return Util::StrUtil::to_lower(this->cli.ask_for_options(prompt));
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

    string Game::ask_user_for_name(string question)
    {
        return this->cli.ask_for_string(question);
    }

    void Game::quit()
    {
        this->_running = false;
    }
}