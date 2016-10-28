//
// Created by mafn on 10/28/16.
//

#include "HitChancePotion.hpp"
#include "player/Player.hpp"

namespace Items {

    HitChancePotion::HitChancePotion()
        : Item("Attack stat potion", "Said to boost your attack", 1)
    {
    }

    HitChancePotion::HitChancePotion(const HitChancePotion &obj)
        : Item(obj._name, obj._description, obj._uses)
    {

    }

    HitChancePotion *HitChancePotion::clone()
    {
        return new HitChancePotion(*this);
    }

    void HitChancePotion::use_handler(Player::Player *target)
    {
        Stats& stats = target->get_stats();
        stats.hit_chance += 5;
    }
}