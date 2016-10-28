//
// Created by mafn on 10/28/16.
//

#include "Whetstone.hpp"
#include "player/Player.hpp"

namespace Items {

    WhetStone::WhetStone()
        : Item("A whetstone", "Used to sharpen your weapon", 1)
    {
    }

    WhetStone::WhetStone(const WhetStone &obj)
        : Item(obj._name, obj._description, obj._uses)
    {

    }

    WhetStone *WhetStone::clone()
    {
        return new WhetStone(*this);
    }

    void WhetStone::use_handler(Player::Player *target)
    {
        target->get_weapon()->increase_max_damage(5);
    }
}