//
// Created by jazula on 10/17/16.
//

#include <iostream>
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
                Floor* new_floor = _floor_generator.generate_floor(height, width);
                new_floor->set_level_range(this->_get_level_range((int)index, (int)n_floors));
                floors.push_back(new_floor);
            }

            return Dungeon(floors);
        }

        Dungeon DungeonGenerator::create_dungeon(DungeonDimensions dimensions)
        {
            return this->create_dungeon(dimensions.floors, dimensions.height, dimensions.width);
        }

        level_range DungeonGenerator::_get_level_range(int floor_number, int number_of_floors)
        {
            int step_size = number_of_floors / (int)this->_level_strengths.size();
            int index = floor_number / step_size;

            if(index >= (int)_level_strengths.size()){
                index = (int)_level_strengths.size() - 1;
            }

            std::cout << _level_strengths[index].first << "-" << _level_strengths[index].second << std::endl;
            return _level_strengths[index];
        }

    }
}