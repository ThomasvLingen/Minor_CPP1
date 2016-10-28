//
// Created by mafn on 10/28/16.
//

#ifndef MINOR_CPP1_HITCHANCEPOTION_HPP
#define MINOR_CPP1_HITCHANCEPOTION_HPP

#include <items/Item.hpp>
#include <player/Stats.hpp>

namespace Items {
    using Player::Stats;

    class HitChancePotion : public Item {
    public:
        HitChancePotion();
        HitChancePotion(const HitChancePotion& obj);
        HitChancePotion* clone();

        virtual void use_handler(Player::Player *target) override;
    };
}


#endif //MINOR_CPP1_HITCHANCEPOTION_HPP
