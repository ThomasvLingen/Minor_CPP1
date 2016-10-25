//
// Created by mafn on 10/21/16.
//

#include <util/StrUtil.hpp>
#include <states/MenuState.hpp>
#include "Game.hpp"

namespace Game {

    Game::Game()
    {
        this->current_state = new States::MenuState(*this);
        this->old_state = nullptr;
    }

    Game::~Game()
    {
        if (this->current_state != nullptr) {
            delete this->current_state;
        }
    }

    string Game::ask_user_for_options(CLI::OptionsQuestion prompt)
    {
        return Util::StrUtil::to_lower(this->cli.ask_for_options(prompt));
    }

    void Game::run()
    {
        while(this->running) {
            this->current_state->run();
            this->delete_old_state();
        }
    }

    void Game::change_state(States::State *state)
    {
        this->old_state = this->current_state;

        this->current_state = state;
    }

    void Game::delete_old_state()
    {
        if (this->old_state != nullptr) {
            delete this->old_state;
        }

        this->old_state = nullptr;
    }

    string Game::ask_user_for_name(string question)
    {
        return this->cli.ask_for_string(question);
    }
}