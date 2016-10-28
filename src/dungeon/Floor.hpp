//
// Created by jazula on 10/17/16.
//

#ifndef MINOR_CPP1_FLOOR_HPP
#define MINOR_CPP1_FLOOR_HPP


#include "Room.hpp"
#include <vector>
#include <map>

namespace Dungeon
{
    using std::size_t;
    using std::vector;
    using std::map;
    using std::pair;

    typedef pair<int,int> level_range;

    class Floor { //perhaps make functions to interact and set map instead of making it public (maybe even friend classes?)
    public:
        Floor(size_t height, size_t width);

        virtual ~Floor();
        void set_room(Room *room_ptr);
        Room *get_room(Location location);
        void print_raw_map(); //perhaps return a string instead of printing it
        size_t get_height();
        size_t get_width();
        void set_level_range(level_range range);

    private:
        level_range _level_range;
        vector<vector<Room *>> _map;
        vector<vector<int>> _adjacency_matrix;
        size_t _height;
        size_t _width;
        map<RoomType, char> _room_type_to_char = {
            {RoomType::normal,        'N'},
            {RoomType::end,           'E'},
            {RoomType::boss,          '@'},
            {RoomType::start,         'S'},
            {RoomType::stair_down,    'D'},
            {RoomType::stair_up,      'U'}
        };

        void check_location(Location location);
        char get_room_print_char(Room* room);
        bool are_rooms_connected(Room *current_room, Room *next_room);
        void print_row(vector<Room*>& row);
        void print_vertical_tunnels(vector<Room*>& current_row, vector<Room*>& next_row);
    };

}
#endif //MINOR_CPP1_FLOOR_HPP
