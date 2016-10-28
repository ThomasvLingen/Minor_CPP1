//
// Created by jazula on 10/17/16.
//

#include <fmt/format.h>
#include <util/RandomUtil.hpp>
#include "RoomGenerator.hpp"

#define ITEM_CHANGE_PERCENTAGE 6

namespace Dungeon
{
    namespace Generator
    {
        using fmt::format;
        using Util::RandomUtil;

        RoomGenerator::RoomGenerator(EnemyFactory* enemyFactory, ItemFactory* itemFactory)
        : _enemy_factory(enemyFactory)
        , _item_factory(itemFactory)
        {

        }

        RoomGenerator::~RoomGenerator()
        {}

        Room *RoomGenerator::generateRoom(RoomType roomType, Location location)
        {
            Room* new_room = new Room(roomType, location, generate_random_description());
            add_random_monsters(new_room);
            add_random_item(new_room);

            return new_room;
        }

        string RoomGenerator::generate_random_description()
        {
            int size_index  = RANDOM.get_random_int(0, _size_options.size()  - 1);
            int light_index = RANDOM.get_random_int(0, _light_options.size() - 1);
            int clean_index = RANDOM.get_random_int(0, _clean_options.size() - 1);

            return format("It is a {0} {1} room, which looks very {2}",
                          _size_options[size_index],
                          _light_options[light_index],
                          _clean_options[clean_index]);
        }

        void RoomGenerator::add_random_monsters(Room *room)
        {
            int random_amount = RANDOM.get_random_int(0, 3);

            for(int count = 0; count <= random_amount; count++){
                Enemy* monster = _enemy_factory->create_random_enemy(_min_level, _max_level).clone();
                room->monsters.push_back(monster);
            }
        }

        void RoomGenerator::set_min_max_monster_level(int min, int max)
        {
            this->_min_level = min;
            this->_max_level = max;
        }

        void RoomGenerator::add_random_item(Room *room)
        {
            bool add_item = RANDOM.weighted_coin_toss(ITEM_CHANGE_PERCENTAGE);
            //use the weighted int function when creating more than one item

            if(add_item){
                room->item = _item_factory->get_random_item();
            }
        }
    }
}
