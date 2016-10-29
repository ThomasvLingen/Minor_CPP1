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
    using std::vector;
    using std::pair;


    class EnemyFactory {
    public:
        EnemyFactory(string monsters_file_name);

        Enemy create_enemy(string name);
        Enemy create_random_enemy(int min_level, int max_level);
        Enemy create_random_boss();

    private:
        MonsterMap _known_monsters;
        vector<string> get_possible_enemies(int min_level, int max_level);
    };
}


#endif //MINOR_CPP1_ENEMYFACTORY_HPP
