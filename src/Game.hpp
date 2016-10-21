//
// Created by mafn on 10/21/16.
//

#ifndef MINOR_CPP1_GAME_HPP
#define MINOR_CPP1_GAME_HPP

#include <states/State.hpp>
#include <states/CommandLineInterface.hpp>

namespace Game {
    using std::string;

    class Game {
    public:
        Game();
        ~Game();

        CLI::CommandLineInterface cli;
        States::State* current_state = nullptr;
        bool running = true;

        void run();
        void change_state(States::State* state);
        string ask_user_for_options(CLI::OptionsQuestion prompt);
    };
}


#endif //MINOR_CPP1_GAME_HPP
