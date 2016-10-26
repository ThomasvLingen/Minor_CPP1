//
// Created by mafn on 10/24/16.
//

#include "PlayerCollection.hpp"

namespace Player {

    PlayerCollection::PlayerCollection()
    {

    }

    void PlayerCollection::add_player(Player *to_add)
    {
        this->players.push_back(to_add);
    }

    PlayerCollection::~PlayerCollection()
    {
        for (Player* player : this->players) {
            delete player;
        }
    }

    void PlayerCollection::remove_player(Player *to_remove)
    {
        this->players.erase(std::remove(this->players.begin(), this->players.end(), to_remove), this->players.end());

        delete to_remove;
    }
}
