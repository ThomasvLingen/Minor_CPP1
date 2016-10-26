//
// Created by jazula on 10/17/16.
//

#ifndef MINOR_CPP1_ROOM_HPP
#define MINOR_CPP1_ROOM_HPP

#include <vector>
#include <string>
#include "monsters/Enemy.hpp"
#include "items/Item.hpp"

namespace Dungeon
{

    class Room {
    public: //enum has to be declared before variable
        enum RoomType {
            start, end, boss, normal, stair_up, stair_down
        }; //not visited roomtype, not actually a type?
        struct Location {
            int width_index;
            int height_index;
        };

    public:
        std::vector<Monsters::Enemy> monsters;
        std::vector<Item> items;
        RoomType room_type;
        Location location;


    private:
        std::string _description;

    };

}
#endif //MINOR_CPP1_ROOM_HPP
