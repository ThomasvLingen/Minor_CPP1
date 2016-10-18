//
// Created by jazula on 10/17/16.
//

#include "Enemy.hpp"

namespace Monsters {
    Enemy::Enemy(std::string name, int level, int hit_chance, int hit_times, Monsters::Damage damage, int defence, int health)
    {
        this->name = name;
        this->level = level;
        this->hit_chance = hit_chance;
        this->hit_times = hit_times;
        this->damage = damage;
        this->defence = defence;
        this->health = health;
    }

    Enemy::Enemy(const Enemy &obj)
    {
        this->name = obj.name;
        this->level = obj.level;
        this->hit_chance = obj.hit_chance;
        this->hit_times = obj.hit_times;
        this->damage = obj.damage;
        this->defence = obj.defence;
        this->health = obj.health;
    }

    Enemy &Enemy::operator=(const Enemy &obj)
    {
        this->name = obj.name;
        this->level = obj.level;
        this->hit_chance = obj.hit_chance;
        this->hit_times = obj.hit_times;
        this->damage = obj.damage;
        this->defence = obj.defence;
        this->health = obj.health;

        return *this;
    }
}
