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
            DungeonGenerator();
            virtual ~DungeonGenerator();
            Dungeon create_dungeon(size_t n_floors, size_t height, size_t width);

        private:
            FloorGenerator floorGenerator;
        };

    }
}
#endif //MINOR_CPP1_DUNGEONGENERATOR_HPP
