//
// Created by jazula on 10/17/16.
//

#include "Dungeon.hpp"

namespace Dungeon
{

    Dungeon::Dungeon(vector<Floor *> floors)
    {
        this->floors = floors;
    }

    Dungeon::~Dungeon()
    {
        for (Floor *floor : floors) {
            delete floor;
        }
    }

}