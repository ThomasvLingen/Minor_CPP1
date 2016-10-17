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