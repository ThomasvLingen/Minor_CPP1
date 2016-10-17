//
// Created by jazula on 10/17/16.
//

#include "Dungeon.hpp"

Dungeon::Dungeon(std::vector<Floor *> floors)
{
    this->_floors = floors;
}

Dungeon::~Dungeon()
{
    for (Floor *floor : _floors) {
        delete floor;
    }
}
