//
// Created by jazula on 10/17/16.
//

#ifndef MINOR_CPP1_FLOOR_HPP
#define MINOR_CPP1_FLOOR_HPP


#include "Room.hpp"
#include <vector>

class Floor { //perhaps make functions to interact and set map instead of making it public (maybe even friend classes?)
public:
    Floor(std::size_t height, std::size_t width);
    virtual ~Floor();

    void set_room(Room *room_ptr);
    Room* get_room(Room::Location location);
    void print_raw_map(); //perhaps return a string instead of printing it
    size_t get_height();
    size_t get_width();

private:
    std::vector<std::vector<Room*>> _map;
    std::vector<std::vector<int>> _adjacency_matrix;
    size_t _height;
    size_t _width;
};


#endif //MINOR_CPP1_FLOOR_HPP
