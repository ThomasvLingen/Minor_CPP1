//
// Created by mafn on 10/21/16.
//

#include "Player.hpp"
#include "util/RandomUtil.hpp"

#include <cmath>

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
        this->defence = 20;
    }

    bool Player::roll_hit()
    {
        return Util::RandomUtil::get_instance().weighted_coin_toss(this->attack);
    }
}