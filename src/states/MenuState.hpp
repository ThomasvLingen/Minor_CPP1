//
// Created by mafn on 10/21/16.
//

#ifndef MINOR_CPP1_MENUSTATE_HPP
#define MINOR_CPP1_MENUSTATE_HPP

#include <string>

#include "State.hpp"
#include "CommandLineInterface.hpp"

namespace Game {
    class Game;
}

namespace States {
    using std::string;
    using std::cout;
    using std::endl;

    class MenuState : public State {
    public:
        CLI::OptionsQuestion menu = {
            .question= "Welcome to Not Rogue™, please select something to do from the menu",
            .options = {"Create character", "Credits", "Quit"}
        };

        string credits = R"(Made by:
Jorg de bont
Thomas van Lingen
)";

        bool state_active = true;

        MenuState(Game::Game& game);
        virtual ~MenuState();
        virtual void run();
    };
}

#endif //MINOR_CPP1_MENUSTATE_HPP
