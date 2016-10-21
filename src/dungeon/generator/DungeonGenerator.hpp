//
// Created by jazula on 10/17/16.
//

#ifndef MINOR_CPP1_DUNGEONGENERATOR_HPP
#define MINOR_CPP1_DUNGEONGENERATOR_HPP


#include <dungeon/Dungeon.hpp>

class DungeonGenerator {

public:
    DungeonGenerator();
    ~DungeonGenerator();
    static Dungeon create_dungeon(std::size_t n_floors, std::size_t height, std::size_t width);

private:

};


#endif //MINOR_CPP1_DUNGEONGENERATOR_HPP
