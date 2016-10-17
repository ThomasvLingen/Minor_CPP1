//
// Created by jazula on 10/17/16.
//

#ifndef MINOR_CPP1_ROOM_HPP
#define MINOR_CPP1_ROOM_HPP

#include <vector>
#include <string>
#include "monsters/Enemy.hpp"
#include "items/Item.hpp"

class Room {

    enum RoomType { start, end, boss, normal, stair_up, stair_down}; //not visited roomtype, not actually a type?

public:
    std::vector<Enemy>  monsters;
    std::vector<Item>   items;
private:
    std::string description;

};


#endif //MINOR_CPP1_ROOM_HPP
