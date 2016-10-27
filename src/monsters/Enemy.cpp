//
// Created by jazula on 10/17/16.
//

#include "Enemy.hpp"

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
}
