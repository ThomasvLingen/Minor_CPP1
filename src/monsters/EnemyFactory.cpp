//
// Created by mafn on 10/17/16.
//

#include "EnemyFactory.hpp"

namespace Monsters
{
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
}