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

    class Floor { //perhaps make functions to interact and set map instead of making it public (maybe even friend classes?)
    public:
        Floor(size_t height, size_t width);

        virtual ~Floor();
        void set_room(Room *room_ptr);
        Room *get_room(Location location);
        void print_raw_map(); //perhaps return a string instead of printing it
        size_t get_height();
        size_t get_width();

    private:
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
    };

}
#endif //MINOR_CPP1_FLOOR_HPP
