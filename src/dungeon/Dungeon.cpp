//
// Created by jazula on 10/17/16.
//

#include <algorithm>
#include "Dungeon.hpp"


namespace Dungeon
{

    Dungeon::Dungeon()
    {

    }

    Dungeon::~Dungeon()
    {
        for (Floor *floor : this->floors) {
            delete floor;
        }
    }

    void Dungeon::add_floor(Floor *floor)
    {
        this->floors.push_back(floor);
    }

    Floor *Dungeon::get_next_floor(Floor *current_floor)
    {
        size_t current_floor_index = this->get_floor_index(current_floor);
        size_t possible_next_floor_index = current_floor_index + 1;

        if (possible_next_floor_index < this->floors.size()) {
            return this->floors[possible_next_floor_index];
        }

        return nullptr;
    }

    Floor *Dungeon::get_prev_floor(Floor *current_floor)
    {
        size_t current_floor_index = this->get_floor_index(current_floor);
        int possible_prev_floor_index = (int)current_floor_index - 1;

        if (possible_prev_floor_index >= 0) {
            return this->floors[possible_prev_floor_index];
        }

        return nullptr;
    }

    size_t Dungeon::get_floor_index(Floor *floor)
    {
        auto floor_it = std::find(this->floors.begin(), this->floors.end(), floor);

        return (size_t)std::distance(this->floors.begin(), floor_it);
    }

}