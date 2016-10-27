//
// Created by mafn on 10/27/16.
//

#ifndef MINOR_CPP1_EQUIPPABLEITEM_HPP
#define MINOR_CPP1_EQUIPPABLEITEM_HPP

#include <player/Stats.hpp>
#include "Item.hpp"


namespace Items {
    using Player::Damage;

    class EquippableItem : public Item {
    public:
        EquippableItem(string name, string description, Damage dmg);

        Damage get_damage();
        void set_damage(Damage new_damage);
        void set_damage(int min, int max);
    private:
        Damage _damage;
    };
};


#endif //MINOR_CPP1_EQUIPPABLEITEM_HPP