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
#include <dungeon/Room.hpp>
#include <dungeon/Floor.hpp>
#include "Stats.hpp"

namespace Player {
    using std::string;
    using std::vector;
    using std::map;
    using std::cout;
    using std::endl;
    using Items::Item;
    using Dungeon::Room;

    class Player {
    public:
        Player(string name);

        vector<Item*> items;
        Room* current_room;

        Stats& get_stats();
        void set_stats(Stats new_stats);
        string& get_name();
        Items::EquippableItem* get_weapon();
        void set_weapon(Items::EquippableItem* new_weapon);

        void use_item(size_t item_index);
        void add_item(Item* item);
        void remove_item(Item* item);
        vector<string> get_item_names();

        void reset_stats();
        void reset_stats_for_creation();

        int get_exp_to_next_level(int current_level);
        int get_exp_to_next_level();
        bool roll_hit();
        bool dodge();
        int roll_attack();
        void attack(Monsters::Enemy* to_attack);

        void print();
        void print_items();
        void print_hp();
        void rest();
        vector<string> to_string();

        void move_direction(Dungeon::Direction direction);
        void give_exp(int amount);

        void level_up();
        const int hit_chance_increase = 5;
        const int defence_increase = 5;
        const int hp_increase = 10;

    private:
        string _name;
        Stats _stats;
        Items::EquippableItem* _weapon;
    };
}


#endif //MINOR_CPP1_PLAYER_HPP
