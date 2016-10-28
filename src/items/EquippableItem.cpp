//
// Created by mafn on 10/27/16.
//

#include "EquippableItem.hpp"
#include <player/Player.hpp>
#include <fmt/format.h>

namespace Items {
    EquippableItem::EquippableItem(string name, string description, Damage dmg)
        : Item(name, description, 1)
        , _damage(dmg)
    {
    }

    EquippableItem::EquippableItem(const EquippableItem &obj)
    : Item(obj._name, obj._description, 1)
    , _damage(obj._damage)
    {

    }

    EquippableItem *EquippableItem::clone()
    {
        return new EquippableItem(*this);
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

    void EquippableItem::use_handler(Player::Player *target)
    {
        target->set_weapon(this);
    }
    /// This returns the weapon in string format. The format is as follows:
    /// <name;description;min_damage;max_damage>
    /// \return
    string EquippableItem::to_string()
    {
        return fmt::format("<{};{};{}-{}>", this->get_name(), this->get_description(), this->get_damage().min, this->get_damage().max);
    }

    void EquippableItem::increase_max_damage(int damage_increase)
    {
        this->_damage.max += damage_increase;
    }
}

