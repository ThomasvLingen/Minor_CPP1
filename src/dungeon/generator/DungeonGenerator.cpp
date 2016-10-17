//
// Created by jazula on 10/17/16.
//

#include "DungeonGenerator.hpp"
#include "FloorGenerator.hpp"

DungeonGenerator::DungeonGenerator()
{

}

DungeonGenerator::~DungeonGenerator()
{

}

Dungeon DungeonGenerator::createDungeon(std::size_t n_floors, std::size_t height, std::size_t width)
{
    std::vector<Floor*> floors;
    floors.reserve(n_floors);

    for(int index = 0; index < n_floors; index++){
        floors.push_back(FloorGenerator::generateFloor(height, width));
    }

    return Dungeon(floors);
}