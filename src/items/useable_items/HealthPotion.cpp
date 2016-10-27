//
// Created by mafn on 10/27/16.
//

#include "HealthPotion.hpp"
#include <player/Player.hpp>

namespace Items {
    HealthPotion::HealthPotion()
    : Item("Health potion", "Refills your health")
    {

    }

    void HealthPotion::use(Player::Player *target)
    {
        Stats &stats = target->get_stats();
        stats.health.current_health = stats.health.max_health;
    }
}
