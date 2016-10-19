//
// Created by jazula on 10/17/16.
//

#include <iostream>
#include "Floor.hpp"

Floor::Floor(std::size_t height, std::size_t width)
{
    this->_height = height;
    this->_width = width;
    this->_map.reserve(height);
    for (int index = 0; index < (int) height; index++) {
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

void Floor::setRoom(Room::Location location, Room *room_ptr)
{
    this->_map[location.height_index][location.width_index] = room_ptr;
}

Room *Floor::getRoom(Room::Location location)
{
    return this->_map[location.height_index][location.width_index];
}

void Floor::printRawMap()
{
    for (std::vector<Room *> room_vector : _map) {
        for (Room *room : room_vector) {
            char toPrint;
            if (room == nullptr) {
                toPrint = '.';
            } else {
                switch (room->room_type) { //make a map for this
                    case Room::normal:
                        toPrint = 'N';
                        break;
                    case Room::start:
                        toPrint = 'S';
                        break;
                    case Room::end:
                        toPrint = 'E';
                        break;
                    default:
                        break;
                }
            }
            std::cout << toPrint;
        }
        std::cout << std::endl;
    }
}
