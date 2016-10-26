//
// Created by mafn on 10/21/16.
//

#ifndef MINOR_CPP1_CREATECHARACTERSTATE_HPP
#define MINOR_CPP1_CREATECHARACTERSTATE_HPP

#include <iostream>
#include <player/Player.hpp>
#include <string>

#include "State.hpp"
#include "CommandLineInterface.hpp"


namespace Game {
    class Game;
}

namespace States {
    using std::cout;
    using std::endl;
    using std::string;
    using Player::Player;
    using ::Player::Stats;
    using CLI::NumberQuestion;

    class CreateCharacterState : public State {
    public:
        CreateCharacterState(Game::Game& game);
        virtual ~CreateCharacterState();

        void run();
        Player* create_character();
        int allocate_stat(int& points_left, int min, int max, int base_stat, int points_per_stat, string stat_name);
    };
}


#endif //MINOR_CPP1_CREATECHARACTERSTATE_HPP
