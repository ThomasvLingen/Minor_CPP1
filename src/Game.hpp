//
// Created by mafn on 10/21/16.
//

#ifndef MINOR_CPP1_GAME_HPP
#define MINOR_CPP1_GAME_HPP

#include <states/State.hpp>
#include <states/CommandLineInterface.hpp>
#include <player/PlayerCollection.hpp>

namespace Game {
    using std::string;

    class Game {
    public:
        Game();
        ~Game();

        CLI::CommandLineInterface cli;
        States::State* current_state;
        States::State* old_state;
        bool running = true;
        Player::PlayerCollection players;

        void run();
        void change_state(States::State* state);
        string ask_user_for_options(CLI::OptionsQuestion prompt);
        string ask_user_for_name(string question);
        void delete_old_state();
    };
}


#endif //MINOR_CPP1_GAME_HPP