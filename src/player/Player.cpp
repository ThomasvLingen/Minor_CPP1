//
// Created by mafn on 10/21/16.
//

#include "Player.hpp"
#include "util/RandomUtil.hpp"

#include <cmath>
#include <fmt/format.h>

namespace Player {

    Player::Player(string name)
    {
        this->name = name;
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
        return this->get_exp_to_next_level(this->level);
    }

    /// \brief Resets the player's stats to base stats
    void Player::reset_stats()
    {
        this->level = 1;
        this->health = Health {
            .max_health = 10,
            .current_health = 10
        };
        this->exp = 0;
        this->attack = 50;
        this->defence = 30;
    }



    bool Player::roll_hit()
    {
        return RANDOM.weighted_coin_toss(this->attack);
    }

    void Player::reset_stats_for_creation()
    {
        this->level = 1;
        this->health = Health {
            .max_health = 10,
            .current_health = 10
        };
        this->exp = 0;
        this->attack = 30;
        this->defence = 20;
    }

    void Player::set_max_health(int new_health)
    {
        this->health = Health {
            .max_health = new_health,
            .current_health = new_health
        };
    }

    void Player::print()
    {
        // TODO: once items are ready, print items
        cout << fmt::format("[{}]", this->name) << endl;
        cout << fmt::format("Level: {} exp [{}-{}]", this->level, this->exp, this->get_exp_to_next_level()) << endl;
        cout << fmt::format("Health: {}/{}", this->health.current_health, this->health.max_health) << endl;
        cout << fmt::format("ATK/DEF: {}/{}", this->attack, this->defence) << endl;
    }
}