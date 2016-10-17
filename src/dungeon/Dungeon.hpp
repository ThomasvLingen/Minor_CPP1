//
// Created by jazula on 10/17/16.
//

#ifndef MINOR_CPP1_DUNGEON_HPP
#define MINOR_CPP1_DUNGEON_HPP


#include <vector>
#include "Floor.hpp"

class Dungeon {
public:
    Dungeon(std::vector<Floor*> floors);
    virtual ~Dungeon();

private:
    std::vector<Floor*> _floors;
};


#endif //MINOR_CPP1_DUNGEON_HPP
