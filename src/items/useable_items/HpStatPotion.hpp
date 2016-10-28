//
// Created by mafn on 10/28/16.
//

#ifndef MINOR_CPP1_HPSTATPOTION_HPP
#define MINOR_CPP1_HPSTATPOTION_HPP

#include <items/Item.hpp>
#include <player/Stats.hpp>

namespace Items {
    using Player::Stats;

    class HpStatPotion : public Item {
    public:
        HpStatPotion();
        HpStatPotion(const HpStatPotion& obj);
        HpStatPotion* clone();

        virtual void use_handler(Player::Player *target) override;

    };
}


#endif //MINOR_CPP1_HPSTATPOTION_HPP
