//
// Created by mafn on 10/17/16.
//

#include <util/RandomUtil.hpp>
#include "EnemyFactory.hpp"

namespace Monsters
{
    using Util::RandomUtil;

    EnemyFactory::EnemyFactory(string monsters_file_name)
    {
        this->_known_monsters = MonsterFileParser::parse_monsters_file(monsters_file_name);
    }

    /// \brief This function returns an enemy object to copy, the caller has to copy the enemy object
    /// \param name Name of the enemy to copy
    /// \return Enemy to copy
    Enemy EnemyFactory::create_enemy(string name)
    {
        return this->_known_monsters.at(name);
    }

    Enemy EnemyFactory::create_random_enemy(int min_level, int max_level)
    {
        vector<string> possible_enemies = get_possible_enemies(min_level,max_level);
        int random_index = RANDOM.get_random_int(0, possible_enemies.size() - 1);

        if(possible_enemies.size() == 0){
            throw std::invalid_argument("No enemies between these levels");
        }

        return create_enemy(possible_enemies[random_index]);
    }

    vector<string> EnemyFactory::get_possible_enemies(int min_level, int max_level)
    {
        vector<string> possible_enemies;

        for(auto possible_enemy : this->_known_monsters){
            int level = possible_enemy.second.get_stats().level;
            if(level >= min_level && level <= max_level){
                possible_enemies.push_back(possible_enemy.first);
            }
        }

        return possible_enemies;
    }
}