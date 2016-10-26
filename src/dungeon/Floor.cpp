//
// Created by jazula on 10/17/16.
//

#include <iostream>
#include <stdexcept>
#include "Floor.hpp"

namespace Dungeon
{

    Floor::Floor(std::size_t height, std::size_t width)
    : _height(height)
    , _width(width)
    {
        this->_map.reserve(height);
        for (size_t index = 0; index < height; index++) {
            _map.push_back(std::vector<Room *>());
            _map[index].resize(width);
        }
    }

    Floor::~Floor()
    {
        for (std::vector<Room *> room_vector : _map) {
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

    Room *Floor::get_room(Room::Location location)
    {
        check_location(location);

        return this->_map[location.height_index][location.width_index];
    }

    void Floor::print_raw_map()
    {
        for (std::vector<Room *> room_vector : _map) {
            for (Room *room : room_vector) {
                char to_print;
                if (room == nullptr) {
                    to_print = '.';
                } else {
                    switch (room->room_type) { //make a map for this
                        case Room::normal:
                            to_print = 'N';
                            break;
                        case Room::start:
                            to_print = 'S';
                            break;
                        case Room::end:
                            to_print = 'E';
                            break;
                        default:
                            break;
                    }
                }
                std::cout << to_print << " ";
            }
            std::cout << std::endl;
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

    void Floor::check_location(Room::Location location)
    {
        if((size_t)location.width_index < 0 || (size_t)location.width_index > this->_width - 1
           || (size_t)location.height_index < 0 || (size_t)location.height_index > this->_height - 1){

            throw std::invalid_argument("Location is not valid");
        }
    }

}