//
// Created by mafn on 10/24/16.
//

#ifndef MINOR_CPP1_PLAYERCOLLECTION_HPP
#define MINOR_CPP1_PLAYERCOLLECTION_HPP

#include <vector>
#include <algorithm>
#include "Player.hpp"

namespace Player {
    using std::vector;

    class PlayerCollection {
    public:
        PlayerCollection();
        virtual ~PlayerCollection();

        // this is public for for loops and the like
        // Making a getter for this is bloat
        vector<Player*> players;

        void add_player(Player* to_add);
        void remove_player(Player* to_remove);
    };
}


#endif //MINOR_CPP1_PLAYERCOLLECTION_HPP
