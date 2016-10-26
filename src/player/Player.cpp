//
// Created by mafn on 10/21/16.
//

#include "Player.hpp"
#include "util/RandomUtil.hpp"

#include <cmath>
#include <fmt/format.h>

namespace Player {

    Player::Player(string name)
    : _name(name)
    {
        this->reset_stats();
    }

    /// \brief this function will return the exp needed for the next level, which scales in an exponential fashion
    /// \param current_level the player's current level
    /// \return exp required to level up
    int Player::get_exp_to_next_level(int current_level)
    {
        return (int)(pow(2, current_level-1) * 10);
    }

    int Player::get_exp_to_next_level()
    {
        return this->get_exp_to_next_level(this->get_stats().level);
    }

    /// \brief Resets the player's stats to base stats
    void Player::reset_stats()
    {
        Stats& stats = this->get_stats();

        stats.level = 1;
        stats.health = Health {
            .max_health = 10,
            .current_health = 10
        };
        stats.exp = 0;
        stats.hit_chance = 50;
        stats.hit_times = 1;
        stats.defence = 30;
    }

    bool Player::roll_hit()
    {
        return RANDOM.weighted_coin_toss(this->get_stats().hit_chance);
    }

    void Player::reset_stats_for_creation()
    {
        this->reset_stats();

        Stats& stats = this->get_stats();
        stats.hit_chance = 30;
        stats.defence = 20;
    }

    void Player::print()
    {
        Stats& stats = this->get_stats();

        // TODO: once items are ready, print items
        cout << fmt::format("[{}]", this->get_name()) << endl;
        cout << fmt::format("Level: {} exp [{}-{}]", stats.level, stats.exp, this->get_exp_to_next_level()) << endl;
        cout << fmt::format("Health: {}/{}", stats.health.current_health, stats.health.max_health) << endl;
        cout << fmt::format("ATK/DEF: {}/{}", stats.hit_chance, stats.defence) << endl;
    }

    Stats &Player::get_stats()
    {
        return this->_stats;
    }

    string &Player::get_name()
    {
        return this->_name;
    }

    void Stats::set_max_health(int new_health)
    {
        this->health = Health {
            .max_health = new_health,
            .current_health = new_health
        };
    }
}