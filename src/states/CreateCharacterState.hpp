//
// Created by mafn on 10/21/16.
//

#ifndef MINOR_CPP1_CREATECHARACTERSTATE_HPP
#define MINOR_CPP1_CREATECHARACTERSTATE_HPP

#include <iostream>
#include <player/Player.hpp>

#include "State.hpp"
#include "CommandLineInterface.hpp"


namespace Game {
    class Game;
}

namespace States {
    using std::cout;
    using std::endl;
    using Player::Player;
    using CLI::NumberQuestion;

    class CreateCharacterState : public State {
    public:
        CreateCharacterState(Game::Game& game);
        virtual ~CreateCharacterState();

        void run();
        Player* create_player();
    };
}


#endif //MINOR_CPP1_CREATECHARACTERSTATE_HPP
