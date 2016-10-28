//
// Created by jazula on 10/17/16.
//

#include "Room.hpp"

namespace Dungeon
{


    Room::Room(RoomType room_type, Location location, string _description)
    : room_type(room_type)
    , location(location)
    , _description(_description)
    {
        this->item = nullptr;
    }

    Room::~Room()
    {
        for(Enemy* enemy : monsters){
            delete(enemy);
        }

        delete(item);
    }

    const string &Room::get_description()
    {
        return this->_description;
    }

    bool Room::is_discovered()
    {
        return _discovered;
    }
}
