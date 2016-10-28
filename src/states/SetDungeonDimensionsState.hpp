//
// Created by mafn on 10/28/16.
//

#ifndef MINOR_CPP1_SETDUNGEONDIMENSIONSSTATE_HPP
#define MINOR_CPP1_SETDUNGEONDIMENSIONSSTATE_HPP


#include <fmt/format.h>
#include "State.hpp"
#include "CommandLineInterface.hpp"

namespace Game {
    class Game;
}

namespace States {
    class SetDungeonDimensionsState : public State {
    public:
        SetDungeonDimensionsState(Game::Game& game);
        virtual ~SetDungeonDimensionsState();

        virtual void run() override;

    private:
        const int _min_dimension = 5;
        const int _max_dimension = 100;
        const int _min_floors = 3;
        const int _max_floors = 10;

        CLI::NumberQuestion _width_question {
            .question = fmt::format("Please enter a width for the dungeon floors [{}-{}]", _min_dimension, _max_dimension),
            .min = _min_dimension,
            .max = _max_dimension
        };

        CLI::NumberQuestion _height_question {
            .question = fmt::format("Please enter a height for the dungeon floors [{}-{}]", _min_dimension, _max_dimension),
            .min = _min_dimension,
            .max = _max_dimension
        };

        CLI::NumberQuestion _floors_question {
            .question = fmt::format("Please enter the amount of floors for the dungeon [{}-{}]", _min_floors, _max_floors),
            .min = _min_dimension,
            .max = _max_dimension
        };
    };
}


#endif //MINOR_CPP1_SETDUNGEONDIMENSIONSSTATE_HPP
