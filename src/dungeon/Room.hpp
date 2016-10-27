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
    using Items::Item;
    using std::string;
    using std::vector;

    enum RoomType {
        start, end, boss, normal, stair_up, stair_down
    }; //not visited roomtype, not actually a type?
    struct Location {
        int width_index;
        int height_index;

        bool operator==(const Location& a) const
        {
            return (width_index == a.width_index && height_index == a.height_index);
        }
    };

    class Room {
    public:
        Room(RoomType room_type, Location location, string _description);
        virtual ~Room();

        vector<Monsters::Enemy> monsters;
        vector<Item> items;
        RoomType room_type;
        Location location;


    private:
        string _description;

    };

}
#endif //MINOR_CPP1_ROOM_HPP
