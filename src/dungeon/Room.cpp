//
// Created by jazula on 10/17/16.
//

#include <util/RandomUtil.hpp>
#include <monsters/EnemyFactory.hpp>
#include <iostream>
#include <algorithm>
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

        std::cout << this->get_description() << std::endl;
        if (this->monsters.size() > 0) {

            std::cout << "You encounter a fearsome band of enemies!" << std::endl;

            this->print_monsters();
        }
    }

    void Room::generate_monsters(Monsters::EnemyFactory& enemy_factory)
    {
        int random_amount = RANDOM.get_random_int(0, 3 - (int)this->monsters.size());
        int min_level = this->container_floor.monster_level_range.first;
        int max_level = this->container_floor.monster_level_range.second;

        for(int count = 0; count < random_amount; count++){
            Enemy* monster = enemy_factory.create_random_enemy(min_level, max_level).clone();
            this->monsters.push_back(monster);
        }
    }

    vector<string> Room::get_monster_names()
    {
        vector<string> names;

        for (auto monster : this->monsters) {
            names.push_back(monster->get_name());
        }

        return names;
    }

    void Room::print_monsters()
    {
        for (auto monster : this->monsters) {
            monster->print();
        }
    }

    void Room::remove_monster(Enemy* to_remove)
    {
        this->monsters.erase(
            std::remove(this->monsters.begin(), this->monsters.end(), to_remove),
            this->monsters.end()
        );
    }
}
