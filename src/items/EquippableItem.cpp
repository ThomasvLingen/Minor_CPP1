//
// Created by mafn on 10/27/16.
//

#include "EquippableItem.hpp"

namespace Items {
    EquippableItem::EquippableItem(string name, string description, Damage dmg)
        : Item(name, description)
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
}

