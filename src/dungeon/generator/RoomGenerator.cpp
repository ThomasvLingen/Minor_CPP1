//
// Created by jazula on 10/17/16.
//

#include "RoomGenerator.hpp"

namespace Dungeon
{
    namespace Generator
    {

        RoomGenerator::RoomGenerator()
        {}

        RoomGenerator::~RoomGenerator()
        {}

        Room *RoomGenerator::generateRoom()
        {
            return new Room();
        }

    }
}
