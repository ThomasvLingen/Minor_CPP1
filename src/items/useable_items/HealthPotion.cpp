//
// Created by mafn on 10/27/16.
//

#include "HealthPotion.hpp"
#include <player/Player.hpp>

namespace Items {
    HealthPotion::HealthPotion()
    : Item("Health potion", "Refills your health", 1)
    {

    }

    HealthPotion::HealthPotion(const HealthPotion &obj)
        : Item(obj._name, obj._description, obj._uses)
    {

    }

    HealthPotion *HealthPotion::clone()
    {
        return new HealthPotion(*this);
    }

    void HealthPotion::use(Player::Player *target)
    {
        this->_uses--;

        Stats &stats = target->get_stats();
        stats.health.current_health = stats.health.max_health;
    }
}
