//
// Created by jazula on 10/17/16.
//

#include <iostream>
#include <stdexcept>
#include "Floor.hpp"

namespace Dungeon
{
    using std::cout;
    using std::endl;

    Floor::Floor(size_t height, size_t width)
    : _height(height)
    , _width(width)
    {
        this->_map.reserve(height);
        for (size_t index = 0; index < height; index++) {
            _map.push_back(vector<Room *>());
            _map[index].resize(width);
        }
    }

    Floor::~Floor()
    {
        for (vector<Room *> room_vector : _map) {
            for (Room *room : room_vector) {
                delete room;
            }
        }
    }

    void Floor::set_room(Room *room_ptr)
    {
        check_location(room_ptr->location);

        this->_map[room_ptr->location.height_index][room_ptr->location.width_index] = room_ptr;
    }

    Room *Floor::get_room(Location location)
    {
        check_location(location);

        return this->_map[location.height_index][location.width_index];
    }

    void Floor::print_raw_map()
    {
        for (vector<Room *> room_vector : _map) {
            for (Room *room : room_vector) {
                char to_print;
                if (room == nullptr) {
                    to_print = '.';
                } else {
                    to_print = this->_room_type_to_char[room->room_type];
                }
                cout << to_print << " ";
            }
            cout << endl;
        }
    }

    size_t Floor::get_width()
    {
        return this->_width;
    }

    size_t Floor::get_height()
    {
        return this->_height;
    }

    void Floor::check_location(Location location)
    {
        if((size_t)location.width_index < 0 || (size_t)location.width_index > this->_width - 1
           || (size_t)location.height_index < 0 || (size_t)location.height_index > this->_height - 1){

            throw std::invalid_argument("Location is not valid");
        }
    }

    void Floor::set_level_range(level_range range)
    {
        this->_level_range = range;
    }

}