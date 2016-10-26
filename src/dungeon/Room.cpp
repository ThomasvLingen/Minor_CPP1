//
// Created by jazula on 10/17/16.
//

#include "Room.hpp"

namespace Dungeon
{


    Room::Room(RoomType room_type, Location location, std::string _description)
    : room_type(room_type)
    , location(location)
    , _description(_description)
    {

    }

    Room::~Room()
    {
        //TODO: perhaps delete items and monsters if pointers
    }
}
