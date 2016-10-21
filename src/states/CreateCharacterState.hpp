//
// Created by mafn on 10/21/16.
//

#ifndef MINOR_CPP1_CREATECHARACTERSTATE_HPP
#define MINOR_CPP1_CREATECHARACTERSTATE_HPP

#include <iostream>

#include "State.hpp"


namespace Game {
    class Game;
}

namespace States {
    using std::cout;
    using std::endl;

    class CreateCharacterState : public State {
    public:
        CreateCharacterState(Game::Game& game);
        virtual ~CreateCharacterState();

        void run();
    };
}


#endif //MINOR_CPP1_CREATECHARACTERSTATE_HPP
