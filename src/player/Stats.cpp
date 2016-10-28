//
// Created by mafn on 10/26/16.
//
#include <fmt/format.h>
#include "Stats.hpp"

namespace Player {
    void Stats::set_max_health(int new_health)
    {
        this->health = Health {
            .max_health = new_health,
            .current_health = new_health
        };
    }

    /// This returns the stats in string format. The format is as follows:
    /// level;max_health;current_health;exp;hit_chance;hit_times;defence
    /// \return
    string Stats::to_string()
    {
        return fmt::format(
            "{};{};{};{};{};{};{}",
            this->level, this->health.max_health, this->health.current_health, this->exp, this->hit_chance, this->hit_times, this->defence
        );
    }
}