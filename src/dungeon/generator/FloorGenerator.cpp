//
// Created by jazula on 10/17/16.
//

#include "FloorGenerator.hpp"
#include "FloorPlan.hpp"
#include <algorithm>

namespace Dungeon
{
    namespace Generator
    {

        FloorGenerator::FloorGenerator()
        {}

        FloorGenerator::~FloorGenerator()
        {}

        Floor *FloorGenerator::generate_floor(std::size_t height, std::size_t width)
        {
            FloorPlan floorPlan(height, width);
            floorPlan.set_random_start_room();
            floorPlan.generate_end_room_starting_from_start_room();

            return floorPlan.generate_floor_from_plan();
        }

    }
}