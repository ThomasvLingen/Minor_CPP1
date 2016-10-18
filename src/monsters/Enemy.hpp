//
// Created by jazula on 10/17/16.
//

#ifndef MINOR_CPP1_ENEMY_HPP
#define MINOR_CPP1_ENEMY_HPP

#include <string>

namespace Monsters
{
    using std::string;

    struct Damage {
        int min;
        int max;
    };

    class Enemy {
    public:
        Enemy(string name, int level, int hit_chance, int hit_times, Damage damage, int defence, int health);
        Enemy(const Enemy& obj);
        Enemy& operator=(const Enemy& obj);

        string name;
        int level;
        int hit_chance;
        int hit_times;
        Damage damage;
        int defence;
        int health;
    };
}


#endif //MINOR_CPP1_ENEMY_HPP
