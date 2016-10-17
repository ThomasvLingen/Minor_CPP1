//
// Created by jazula on 10/17/16.
//

#ifndef MINOR_CPP1_FLOOR_HPP
#define MINOR_CPP1_FLOOR_HPP


#include <vector>
#include "Room.hpp"

class Floor {
public:
    Floor(std::size_t height, std::size_t width);
    virtual ~Floor();

private:
    size_t _height;
    size_t _width;

    std::vector<std::vector<Room*>> _map;
    std::vector<std::vector<int>> _adjacency_matrix;
};


#endif //MINOR_CPP1_FLOOR_HPP
