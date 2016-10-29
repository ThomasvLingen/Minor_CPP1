//
// Created by mafn on 10/24/16.
//

#ifndef MINOR_CPP1_PLAYERCOLLECTION_HPP
#define MINOR_CPP1_PLAYERCOLLECTION_HPP

#include <vector>
#include <algorithm>
#include "Player.hpp"

namespace Player {
    using std::vector;

    class PlayerCollection {
    public:
        PlayerCollection();
        virtual ~PlayerCollection();

        // this is public for for loops and the like
        // Making a getter for this is bloat
        vector<Player*> players;

        void add_player(Player* to_add);
        void remove_player(Player* to_remove);
        void empty();
        void select_player(Player* to_select);
        void select_player(size_t index);
        Player* get_selected_player();
        Player* get_player(string name);
        size_t count();

        vector<string> get_player_names();

        void save_players();
        void load_players();

        void print_players();
    private:
        const string _players_file_filename = "./saved_players";
        Player* _selected_player;
    };
}


#endif //MINOR_CPP1_PLAYERCOLLECTION_HPP
