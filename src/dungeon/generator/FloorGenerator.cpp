//
// Created by jazula on 10/17/16.
//

#include "FloorGenerator.hpp"
#include "FloorPlan.hpp"
#include <algorithm>
#include <iostream>

namespace Dungeon
{
    namespace Generator
    {
        using std::vector;

        FloorGenerator::FloorGenerator(EnemyFactory* factory)
        : _room_generator(factory)
        {
        }

        FloorGenerator::~FloorGenerator()
        {}

        Floor *FloorGenerator::generate_floor(size_t height, size_t width)
        {
            FloorPlan floorPlan(height, width);
            floorPlan.set_random_start_room();
            floorPlan.generate_end_room_starting_from_start_room();

            return this->_convert_floor_plan_to_floor(&floorPlan);
        }

        Floor *FloorGenerator::_convert_floor_plan_to_floor(FloorPlan* fp)
        {
            int height_index = 0;
            int width_index = 0;
            Floor *floor = new Floor(fp->get_height(), fp->get_width());
            for (vector<PlanRoomType> row: fp->get_plan()) {
                for (PlanRoomType type: row) {
                    if (type != PlanRoomType::none) {
                        Room *room = convert_type_location_to_room(width_index, height_index, type);
                        floor->set_room(room);
                    }
                    width_index++;
                }
                height_index++;
                width_index = 0;
            }

            return floor;
        }

        Room *FloorGenerator::convert_type_location_to_room(size_t width, size_t height, PlanRoomType type)
        {
            Room *room = _room_generator.generateRoom(
                _plan_room_type_to_room_type_map[type],
                {(int)width, (int)height}
            );

            return room;
        }

    }
}