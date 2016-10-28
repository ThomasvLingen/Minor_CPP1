//
// Created by mafn on 10/28/16.
//

#ifndef MINOR_CPP1_WHETSTONE_HPP
#define MINOR_CPP1_WHETSTONE_HPP


#include <items/Item.hpp>
#include <player/Stats.hpp>

namespace Items {
    using Player::Stats;

    class WhetStone : public Item {
    public:
        WhetStone();
        WhetStone(const WhetStone& obj);
        WhetStone* clone();

        virtual void use_handler(Player::Player *target) override;

    };
}


#endif //MINOR_CPP1_WHETSTONE_HPP
