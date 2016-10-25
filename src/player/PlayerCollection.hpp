//
// Created by mafn on 10/24/16.
//

#ifndef MINOR_CPP1_PLAYERCOLLECTION_HPP
#define MINOR_CPP1_PLAYERCOLLECTION_HPP

#include <vector>
#include "Player.hpp"

namespace Player {
    using std::vector;

    class PlayerCollection {
    public:
        PlayerCollection();
        virtual ~PlayerCollection();

        vector<Player*> players;

        void add_player(Player* to_add);
    };
}


#endif //MINOR_CPP1_PLAYERCOLLECTION_HPP
