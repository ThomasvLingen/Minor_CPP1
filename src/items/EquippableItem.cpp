//
// Created by mafn on 10/27/16.
//

#include "EquippableItem.hpp"
#include <player/Player.hpp>

namespace Items {
    EquippableItem::EquippableItem(string name, string description, Damage dmg)
        : Item(name, description, 1)
        , _damage(dmg)
    {
    }

    Damage EquippableItem::get_damage()
    {
        return this->_damage;
    }

    void EquippableItem::set_damage(Damage new_damage)
    {
        this->_damage = new_damage;
    }

    void EquippableItem::set_damage(int min, int max)
    {
        this->set_damage(Damage {
            .min = min,
            .max = max
        });
    }

    void EquippableItem::use(Player::Player *target)
    {
        target->set_weapon(this);
    }
}

