//
// Created by mafn on 10/28/16.
//

#ifndef MINOR_CPP1_PLAYERFILEPARSER_HPP
#define MINOR_CPP1_PLAYERFILEPARSER_HPP

#include "Player.hpp"

namespace Player {
    using std::vector;
    using std::string;
    using std::stoi;

    class PlayerFileParser {
    public:
        static vector<Player*> parse_players_file(string filename);
        static Player* parse_player(vector<string> player);
        static vector<string> get_player_lines(vector<string>& lines);
        static vector<string> consume_player(vector<string>& lines);

    private:
        static string _get_name(vector<string> props);
        static int _get_level(vector<string> props);
        static int _get_max_health(vector<string> props);
        static int _get_current_health(vector<string> props);
        static int _get_exp(vector<string> props);
        static int _get_hit_chance(vector<string> props);
        static int _get_hit_times(vector<string> props);
        static int _get_defence(vector<string> props);

    };
}


#endif //MINOR_CPP1_PLAYERFILEPARSER_HPP
