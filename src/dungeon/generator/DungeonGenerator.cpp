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

        Dungeon* DungeonGenerator::create_dungeon(size_t n_floors, size_t height, size_t width)
        {
            Floor* new_floor = nullptr;
            Dungeon* dungeon = new Dungeon();

            for (size_t index = 0; index < n_floors; index++) {
                pair<RoomType, RoomType> room_types = get_start_end_room_types((int)index, (int)n_floors);
                _floor_generator.set_dungeon(dungeon);
                new_floor = _floor_generator.generate_floor(height, width, room_types.first, room_types.second);

                if(new_floor == nullptr){
                    std::cout << "Failed to create dungeon" << std::endl;
                    return nullptr;
                }

                new_floor->set_level_range(this->_get_level_range((int)index, (int)n_floors));

                dungeon->add_floor(new_floor);
            }

            return dungeon;
        }

        Dungeon* DungeonGenerator::create_dungeon(DungeonDimensions dimensions)
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

            return _level_strengths[index];
        }

        pair<RoomType, RoomType> DungeonGenerator::get_start_end_room_types(int floor_n, int number_of_floors)
        {
            RoomType start_room = (floor_n == 0) ? RoomType::start : RoomType::stair_up;
            RoomType end_room   = (floor_n == number_of_floors - 1) ? RoomType::boss : RoomType::stair_down;

            return pair<RoomType, RoomType> {start_room, end_room};
        }

    }
}