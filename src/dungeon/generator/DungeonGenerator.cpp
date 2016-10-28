//
// Created by jazula on 10/17/16.
//

#include "DungeonGenerator.hpp"
#include "FloorGenerator.hpp"

namespace Dungeon
{
    namespace Generator
    {

        DungeonGenerator::DungeonGenerator(EnemyFactory* enemyFactory, ItemFactory* itemFactory)
        : _floor_generator(enemyFactory, itemFactory)
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
                floors.push_back(_floor_generator.generate_floor(height, width));
            }

            return Dungeon(floors);
        }

        Dungeon DungeonGenerator::create_dungeon(DungeonDimensions dimensions)
        {
            return this->create_dungeon(dimensions.floors, dimensions.height, dimensions.width);
        }

    }
}