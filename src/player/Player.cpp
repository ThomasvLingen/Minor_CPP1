//
// Created by mafn on 10/21/16.
//

#include "Player.hpp"
#include "util/RandomUtil.hpp"

#include <cmath>
#include <fmt/format.h>

namespace Player {

    Player::Player(string name)
    : current_room(nullptr)
    , _name(name)
    , _weapon(nullptr)
    {
        this->reset_stats();
    }

    /// \brief this function will return the exp needed for the next level, which scales in an exponential fashion
    /// \param current_level the player's current level
    /// \return exp required to level up
    int Player::get_exp_to_next_level(int current_level)
    {
        return (int)(pow(2, current_level-1) * 10);
    }

    int Player::get_exp_to_next_level()
    {
        return this->get_exp_to_next_level(this->get_stats().level);
    }

    /// \brief Resets the player's stats to base stats
    void Player::reset_stats()
    {
        Stats& stats = this->get_stats();

        stats.level = 1;
        stats.health = Health {
            .max_health = 10,
            .current_health = 10
        };
        stats.exp = 0;
        stats.hit_chance = 50;
        stats.hit_times = 1;
        stats.defence = 30;
    }

    bool Player::roll_hit()
    {
        return RANDOM.weighted_coin_toss(this->get_stats().hit_chance);
    }

    void Player::reset_stats_for_creation()
    {
        this->reset_stats();

        Stats& stats = this->get_stats();
        stats.hit_chance = 30;
        stats.defence = 20;
    }

    Stats &Player::get_stats()
    {
        return this->_stats;
    }

    string &Player::get_name()
    {
        return this->_name;
    }

    Items::EquippableItem *Player::get_weapon()
    {
        return this->_weapon;
    }

    void Player::set_weapon(Items::EquippableItem *new_weapon)
    {
        this->_weapon = new_weapon;
    }

    /// This throws an exception if the index is invalid
    /// \param item_index item index to use
    void Player::use_item(size_t item_index)
    {
        Item* target_item;

        try {
            target_item = this->items.at(item_index);
        } catch (std::exception e) {
            cout << "Cannot use item at index " << item_index << endl;
            return;
        }

        // If item is usable, use it!
        if (target_item->is_usable()) {
            target_item->use_handler(this);

            // If item is not usable anymore, remove it from inventory
            if (!target_item->is_usable()) {
                this->remove_item(target_item);
            }
        }
    }

    void Player::add_item(Item *item)
    {
        this->items.push_back(item);
    }

    void Player::remove_item(Item *item)
    {
        this->items.erase(
            std::remove(this->items.begin(), this->items.end(), item),
            this->items.end()
        );
    }

    void Player::print()
    {
        Stats& stats = this->get_stats();

        cout << fmt::format("[{}]", this->get_name()) << endl;
        cout << fmt::format("Level: {} exp [{}-{}]", stats.level, stats.exp, this->get_exp_to_next_level()) << endl;
        cout << fmt::format("Health: {}/{}", stats.health.current_health, stats.health.max_health) << endl;
        cout << fmt::format("ATK/DEF: {}/{}", stats.hit_chance, stats.defence) << endl;
        this->print_items();
    }

    void Player::print_items()
    {
        cout << "Items:" << endl;
        for (size_t item_index = 0; item_index < this->items.size(); item_index++) {
            Item* item = this->items[item_index];

            cout << fmt::format("[{}] {} - {} - {} uses", item_index, item->get_name(), item->get_description(), item->get_uses()) << endl;
        }
    }

    /// This serialises the player into a vector of strings
    /// The format for this is as follows:
    /// [name;stats]
    /// <equipped_item>
    ///
    /// \return
    vector<string> Player::to_string()
    {
        // TODO: Maybe serialise useable items?
        vector<string> lines;

        lines.push_back(fmt::format("[{};{}]", this->get_name(), this->get_stats().to_string()));
        if (this->_weapon != nullptr) {
            lines.push_back(this->_weapon->to_string());
        } else {
            lines.push_back("<>");
        }

        return lines;
    }

    void Player::set_stats(Stats new_stats)
    {
        this->_stats = new_stats;
    }

    void Player::move_direction(Dungeon::Direction direction)
    {
        /// current we are going back and forth a lot with current_room
        // TODO:
        Room* next_room = this->current_room->container_floor.get_room_in_direction(this->current_room, direction);

        if(next_room != nullptr){
            this->current_room = next_room;
        }

    }
}