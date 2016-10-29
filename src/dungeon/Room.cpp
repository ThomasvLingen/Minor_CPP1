//
// Created by jazula on 10/17/16.
//

#include "Room.hpp"

namespace Dungeon
{


    Room::Room(RoomType room_type, Location location, string _description, Floor& container_floor)
    : room_type(room_type)
    , location(location)
    , container_floor(container_floor)
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

    Item *Room::get_item()
    {
        Item* return_item = this->item;
        this->item = nullptr;

        return return_item;
    }
}
