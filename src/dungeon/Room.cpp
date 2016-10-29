//
// Created by jazula on 10/17/16.
//

#include <util/RandomUtil.hpp>
#include <monsters/EnemyFactory.hpp>
#include "Room.hpp"
#include "Floor.hpp"

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

    void Room::discover(Monsters::EnemyFactory& enemy_factory)
    {
        this->_discovered = true;
        this->generate_monsters(enemy_factory);
    }

    void Room::generate_monsters(Monsters::EnemyFactory& enemy_factory)
    {
        int random_amount = RANDOM.get_random_int(0, 3);
        int min_level = this->container_floor.monster_level_range.first;
        int max_level = this->container_floor.monster_level_range.second;

        for(int count = 0; count <= random_amount; count++){
            Enemy* monster = enemy_factory.create_random_enemy(min_level, max_level).clone();
            this->monsters.push_back(monster);
        }
    }
}
