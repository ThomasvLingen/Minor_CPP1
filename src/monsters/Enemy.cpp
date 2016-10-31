//
// Created by jazula on 10/17/16.
//

#include <iostream>
#include <fmt/format.h>
#include <util/RandomUtil.hpp>
#include "Enemy.hpp"
#include <player/Player.hpp>

namespace Monsters {
    Enemy::Enemy(std::string name, int level, int hit_chance, int hit_times, Damage damage, int defence, int health)
    : _name(name)
    , _stats(Stats {
        .level = level,
        .health = Health {
            .max_health = health,
            .current_health = health
        },
        .exp = 0,
        .hit_chance = hit_chance,
        .hit_times = hit_times,
        .defence = defence
    })
    , _damage(damage)
    {
    }

    Enemy::Enemy(const Enemy &obj)
    {
        this->_name = obj._name;
        this->_damage = obj._damage;
        this->_stats = obj._stats;
    }

    Enemy &Enemy::operator=(const Enemy &obj)
    {
        this->_name = obj._name;
        this->_damage = obj._damage;
        this->_stats = obj._stats;

        return *this;
    }

    string Enemy::get_name()
    {
        return this->_name;
    }

    Stats &Enemy::get_stats()
    {
        return this->_stats;
    }

    Damage &Enemy::get_damage()
    {
        return this->_damage;
    }

    Enemy *Enemy::clone()
    {
        return new Enemy(*this);
    }

    void Enemy::print()
    {
        std::cout << fmt::format("{} - {}", this->get_name(), this->get_stats().health.to_string()) << std::endl;
    }

    bool Enemy::dodge()
    {
        if (this->get_stats().defence >= 100) {
            return true;
        } else {
            return RANDOM.weighted_coin_toss(this->get_stats().defence);
        }
    }

    void Enemy::attack_player(Player::Player* player)
    {
        if (this->roll_hit() && !player->dodge()) {
            int damage = this->roll_attack();

            player->get_stats().health.current_health -= damage;

            std::cout << fmt::format("{} attacks you for {} damage!", this->get_name(), damage) << std::endl;
        } else {
            std::cout << fmt::format("{} tried to attack you, but missed!", this->get_name()) << std::endl;
        }
    }

    bool Enemy::roll_hit()
    {
        if (this->get_stats().hit_chance >= 100) {
            return true;
        } else {
            return RANDOM.weighted_coin_toss(this->get_stats().hit_chance);
        }
    }

    int Enemy::roll_attack()
    {
        return RANDOM.get_random_int(this->get_damage().min, this->get_damage().max) * this->get_stats().hit_times;
    }


}
