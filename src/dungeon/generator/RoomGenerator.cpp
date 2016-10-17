//
// Created by jazula on 10/17/16.
//

#include "RoomGenerator.hpp"

RoomGenerator::RoomGenerator()
{}

RoomGenerator::~RoomGenerator()
{}

Room* RoomGenerator::generateRoom()
{
    return new Room();
}
