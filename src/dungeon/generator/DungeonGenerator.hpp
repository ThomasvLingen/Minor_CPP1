//
// Created by jazula on 10/17/16.
//

#ifndef MINOR_CPP1_DUNGEONGENERATOR_HPP
#define MINOR_CPP1_DUNGEONGENERATOR_HPP


#include <dungeon/Dungeon.hpp>
#include "FloorGenerator.hpp"

namespace Dungeon
{
    namespace Generator
    {
        using std::size_t;
        using std::vector;
        using std::pair;

        class DungeonGenerator {

        public:
            DungeonGenerator(EnemyFactory* enemyFactory, ItemFactory* itemFactory);
            virtual ~DungeonGenerator();
            Dungeon create_dungeon(DungeonDimensions dimensions);
            Dungeon create_dungeon(size_t n_floors, size_t height, size_t width);

        private:
            FloorGenerator _floor_generator;
            level_range _get_level_range(int floor_n, int number_of_floors);
            vector<level_range> _level_strengths = {
                {1, 2},
                {2, 4},
                {4, 6},
                {6, 8},
                {8, 10}
            };
        };

    }
}
#endif //MINOR_CPP1_DUNGEONGENERATOR_HPP
