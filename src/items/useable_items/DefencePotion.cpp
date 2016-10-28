//
// Created by mafn on 10/28/16.
//

#include "DefencePotion.hpp"
#include "player/Player.hpp"

namespace Items {

    DefencePotion::DefencePotion()
        : Item("Defence stat potion", "Said to boost your defences", 1)
    {
    }

    DefencePotion::DefencePotion(const DefencePotion &obj)
        : Item(obj._name, obj._description, obj._uses)
    {

    }

    DefencePotion *DefencePotion::clone()
    {
        return new DefencePotion(*this);
    }

    void DefencePotion::use_handler(Player::Player *target)
    {
        Stats& stats = target->get_stats();
        stats.defence += 5;
    }
}