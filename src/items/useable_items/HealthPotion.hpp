//
// Created by mafn on 10/27/16.
//

#ifndef MINOR_CPP1_HEALTHPOTION_HPP
#define MINOR_CPP1_HEALTHPOTION_HPP

#include <items/Item.hpp>
#include <player/Stats.hpp>

namespace Items {
    using Player::Stats;

    class HealthPotion : public Item {
    public:
        HealthPotion();
    private:
    public:
        virtual void use(Player::Player *target) override;
    };
}


#endif //MINOR_CPP1_HEALTHPOTION_HPP
