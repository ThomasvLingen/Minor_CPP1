//
// Created by mafn on 10/21/16.
//

#ifndef MINOR_CPP1_PLAYER_HPP
#define MINOR_CPP1_PLAYER_HPP

#include <string>
#include <vector>
#include <map>
#include <algorithm>

#include <items/Item.hpp>
#include <iostream>
#include <items/EquippableItem.hpp>
#include "Stats.hpp"

namespace Player {
    using std::string;
    using std::vector;
    using std::map;
    using std::cout;
    using std::endl;
    using Items::Item;

    class Player {
    public:
        Player(string name);

        vector<Item*> items;

        Stats& get_stats();
        string& get_name();
        Items::EquippableItem* get_weapon();
        void set_weapon(Items::EquippableItem* new_weapon);

        void use_item(size_t item_index);
        void add_item(Item* item);
        void remove_item(Item* item);

        void reset_stats();
        void reset_stats_for_creation();

        int get_exp_to_next_level(int current_level);
        int get_exp_to_next_level();
        bool roll_hit();

        void print();
        void print_items();
        vector<string> to_string();

    private:
        string _name;
        Stats _stats;
        Items::EquippableItem* _weapon;
    };
}


#endif //MINOR_CPP1_PLAYER_HPP
