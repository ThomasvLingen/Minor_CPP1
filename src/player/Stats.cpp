//
// Created by mafn on 10/26/16.
//
#include "Stats.hpp"

namespace Player {
    void Stats::set_max_health(int new_health)
    {
        this->health = Health {
            .max_health = new_health,
            .current_health = new_health
        };
    }
}