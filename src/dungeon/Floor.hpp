//
// Created by jazula on 10/17/16.
//

#ifndef MINOR_CPP1_FLOOR_HPP
#define MINOR_CPP1_FLOOR_HPP


#include <vector>
#include "Room.hpp"

class Floor {
public:
    Floor();
    ~Floor();

private:
    std::vector<std::vector<Room>>  map;
    std::vector<std::vector<int>>   adjacency_matrix;
};


#endif //MINOR_CPP1_FLOOR_HPP
