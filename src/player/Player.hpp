//
// Created by mafn on 10/21/16.
//

#ifndef MINOR_CPP1_PLAYER_HPP
#define MINOR_CPP1_PLAYER_HPP

#include <string>
#include <vector>
#include <map>

#include <items/Item.hpp>
#include <iostream>
#include "Stats.hpp"

namespace Player {
    using std::string;
    using std::vector;
    using std::map;
    using std::cout;
    using std::endl;

    class Player {
    public:
        Player(string name);

        vector<Item> items;

        Stats& get_stats();
        string& get_name();

        void reset_stats();
        void reset_stats_for_creation();

        int get_exp_to_next_level(int current_level);
        int get_exp_to_next_level();
        bool roll_hit();

        void print();

    private:
        string _name;
        Stats _stats;
    };
}


#endif //MINOR_CPP1_PLAYER_HPP
