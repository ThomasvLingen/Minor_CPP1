//
// Created by jazula on 10/17/16.
//

#include "Floor.hpp"

Floor::Floor(std::size_t height, std::size_t width)
{
    this->_height = height;
    this->_width  = width;
}

Floor::~Floor()
{
    for(std::vector<Room*> room_vector : _map){
        for(Room* room : room_vector){
            delete room;
        }
    }
}

void Floor::setRoom(Room::Location location, Room * room_ptr)
{
    this->_map[location.height_index][location.width_index] = room_ptr;
}

Room *Floor::getRoom(Room::Location location)
{
    return this->_map[location.height_index][location.width_index];
}
