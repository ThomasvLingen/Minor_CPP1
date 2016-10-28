//
// Created by mafn on 10/28/16.
//

#include "HpStatPotion.hpp"
#include "player/Player.hpp"

namespace Items {

    HpStatPotion::HpStatPotion()
    : Item("Max HP stat potion", "Said to boost your vitality", 1)
    {
    }

    HpStatPotion::HpStatPotion(const HpStatPotion &obj)
    : Item(obj._name, obj._description, obj._uses)
    {

    }

    HpStatPotion *HpStatPotion::clone()
    {
        return new HpStatPotion(*this);
    }

    void HpStatPotion::use_handler(Player::Player *target)
    {
        Stats& stats = target->get_stats();
        stats.set_max_health(stats.health.max_health + 3);
    }
}