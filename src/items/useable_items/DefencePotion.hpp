//
// Created by mafn on 10/28/16.
//

#ifndef MINOR_CPP1_DEFENCEPOTION_HPP
#define MINOR_CPP1_DEFENCEPOTION_HPP


#include <items/Item.hpp>
#include <player/Stats.hpp>

namespace Items {
    using Player::Stats;

    class DefencePotion : public Item {
    public:
        DefencePotion();
        DefencePotion(const DefencePotion& obj);
        DefencePotion* clone();

        virtual void use_handler(Player::Player *target) override;

    };
}


#endif //MINOR_CPP1_DEFENCEPOTION_HPP
