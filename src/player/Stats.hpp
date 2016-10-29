//
// Created by mafn on 10/26/16.
//

#ifndef MINOR_CPP1_STATS_HPP
#define MINOR_CPP1_STATS_HPP

#include <string>
#include <fmt/format.h>

namespace Player {

    using std::string;

    struct Health {
        int max_health;
        int current_health;

        string to_string() {
            return fmt::format("{}/{}", this->current_health, this->max_health);
        };
    };

    struct Damage {
        int min;
        int max;
    };

    struct Stats {
        int level;
        Health health;      /// When health reaches 0, the player dies
        int exp;            /// When exp reaches the exp threshhold calculated by `get_exp_to_next_level`, the player levels up
        int hit_chance;     /// Chance to hit in percents
        int hit_times;      /// Times attack will hit in percents
        int defence;        /// Chance for the enemy to miss

        void set_max_health(int new_health);
        string to_string();
    };

}

#endif //MINOR_CPP1_STATS_HPP
