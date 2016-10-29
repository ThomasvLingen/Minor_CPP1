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

    enum Direction {north, east, south, west};

    class Floor { //perhaps make functions to interact and set map instead of making it public (maybe even friend classes?)
    public:
        Floor(size_t height, size_t width);
        virtual ~Floor();

        Room* start_room;
        Room* end_room;

        void set_room(Room *room_ptr);
        Room *get_room(Location location);
        void print_floor(); //perhaps return a string instead of printing it
        void print_floor(bool god_mode);
        size_t get_height();
        size_t get_width();
        void set_level_range(level_range range);
        Room* get_room_in_direction(Room* current_room, Direction direction);
        Location get_new_location_in_direction(Direction direction, Location location);
        vector<Direction> get_available_directions(Room* room);

    private:
        level_range _level_range;
        vector<vector<Room *>> _map;
        size_t _height;
        size_t _width;
        map<RoomType, char> _room_type_to_char = {
            {RoomType::normal,        'n'},
            {RoomType::end,           'E'},
            {RoomType::boss,          'B'},
            {RoomType::start,         'S'},
            {RoomType::stair_down,    'D'},
            {RoomType::stair_up,      'U'}
        };
        map<Direction, pair<int, int>> _direction_to_location_delta = {
            {Direction::west,    {-1, 0}},
            {Direction::east,    {+1, 0}},
            {Direction::south,   {0, -1}},
            {Direction::north,   {0, +1}}
        };
        vector<Direction> _available_directions = {
            {Direction::west},
            {Direction::east},
            {Direction::south},
            {Direction::north}
        };

        void check_location(Location location);
        bool valid_location(Location location);
        char get_room_print_char(Room* room, bool god_mode);
        bool should_draw_tunnel_between_rooms(Room *current_room, Room *next_room, bool god_mode);
        void print_row(vector<Room*>& row, bool god_mode);
        void print_vertical_tunnels(vector<Room*>& current_row, vector<Room*>& next_row, bool god_mode);
    };

}
#endif //MINOR_CPP1_FLOOR_HPP
