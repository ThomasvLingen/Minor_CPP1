//
// Created by jazula on 10/17/16.
//

#include "DungeonGenerator.hpp"
#include "FloorGenerator.hpp"

namespace Dungeon
{
    namespace Generator
    {

        DungeonGenerator::DungeonGenerator()
        {

        }

        DungeonGenerator::~DungeonGenerator()
        {

        }

        Dungeon DungeonGenerator::create_dungeon(size_t n_floors, size_t height, size_t width)
        {
            std::vector<Floor *> floors;
            floors.reserve(n_floors);

            for (size_t index = 0; index < n_floors; index++) {
                floors.push_back(floorGenerator.generate_floor(height, width));
            }

            return Dungeon(floors);
        }

    }
}