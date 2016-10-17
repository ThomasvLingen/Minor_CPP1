//
// Created by jazula on 10/17/16.
//

#ifndef MINOR_CPP1_ROOMGENERATOR_HPP
#define MINOR_CPP1_ROOMGENERATOR_HPP


#include <dungeon/Room.hpp>

class RoomGenerator {
public:
    RoomGenerator();
    virtual ~RoomGenerator();
    static Room* generateRoom();
};


#endif //MINOR_CPP1_ROOMGENERATOR_HPP
