//
// Created by jazula on 10/17/16.
//

#ifndef MINOR_CPP1_ENEMY_HPP
#define MINOR_CPP1_ENEMY_HPP

#include <string>
#include <player/Stats.hpp>

namespace Player {
    class Player;
}

namespace Monsters
{
    using std::string;
    using Player::Stats;
    using Player::Health;
    using Player::Damage;

    class Enemy {
    public:
        Enemy(string name, int level, int hit_chance, int hit_times, Damage damage, int defence, int health);
        Enemy(const Enemy& obj);
        Enemy& operator=(const Enemy& obj);
        Enemy* clone();

        string get_name();
        Stats& get_stats();
        Damage& get_damage();
        bool dodge();

        void attack_player(Player::Player* player);
        bool roll_hit();
        int roll_attack();

        void print();

    private:
        string _name;
        Stats _stats;
        Damage _damage;
    };
}


#endif //MINOR_CPP1_ENEMY_HPP
