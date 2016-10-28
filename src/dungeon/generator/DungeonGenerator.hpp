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

        class DungeonGenerator {

        public:
            DungeonGenerator(EnemyFactory* enemyFactory, ItemFactory* itemFactory);
            virtual ~DungeonGenerator();
            Dungeon create_dungeon(DungeonDimensions dimensions);
            Dungeon create_dungeon(size_t n_floors, size_t height, size_t width);

        private:
            FloorGenerator _floor_generator;
        };

    }
}
#endif //MINOR_CPP1_DUNGEONGENERATOR_HPP
