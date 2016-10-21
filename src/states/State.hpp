//
// Created by jazula on 10/17/16.
//

#ifndef MINOR_CPP1_STATE_HPP
#define MINOR_CPP1_STATE_HPP


namespace Game {
    class Game;
}

namespace States {
    class State {
    public:
        State(Game::Game& game);
        virtual ~State();

        Game::Game& game;
        virtual void run()=0;
    };
}


#endif //MINOR_CPP1_STATE_HPP
