//
// Created by mafn on 10/21/16.
//

#ifndef MINOR_CPP1_GAME_HPP
#define MINOR_CPP1_GAME_HPP

#include <states/State.hpp>
#include <states/CommandLineInterface.hpp>
#include <player/PlayerCollection.hpp>
#include <dungeon/Dungeon.hpp>

namespace Game {
    using std::string;
    using Dungeon::DungeonDimensions;

    class Game {
    public:
        Game();
        ~Game();

        CLI::CommandLineInterface cli;
        Player::PlayerCollection players;

        void run();
        void quit();
        void change_state(States::State* state);
        void set_dungeon_dimensions(DungeonDimensions new_dimensions);

    private:
        bool _running = true;
        States::State* _current_state;
        States::State* _old_state;
        DungeonDimensions dimensions;

        void delete_old_state();
    };
}


#endif //MINOR_CPP1_GAME_HPP
