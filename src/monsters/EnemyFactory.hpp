//
// Created by mafn on 10/17/16.
//

#ifndef MINOR_CPP1_ENEMYFACTORY_HPP
#define MINOR_CPP1_ENEMYFACTORY_HPP

#include <string>

#include "Enemy.hpp"
#include "MonsterFileParser.hpp"


namespace Monsters {
    using std::string;


    class EnemyFactory {
    public:
        EnemyFactory(string monsters_file_name);

        Enemy create_enemy(string name);
    private:
        MonsterMap _known_monsters;
    };
}


#endif //MINOR_CPP1_ENEMYFACTORY_HPP
