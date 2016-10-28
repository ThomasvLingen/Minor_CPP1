//
// Created by jazula on 10/17/16.
//

#ifndef MINOR_CPP1_ROOMGENERATOR_HPP
#define MINOR_CPP1_ROOMGENERATOR_HPP


#include <dungeon/Room.hpp>
#include <monsters/EnemyFactory.hpp>

namespace Dungeon
{
    namespace Generator
    {
        using std::string;
        using std::vector;
        using Monsters::EnemyFactory;

        class RoomGenerator {
        public:
            RoomGenerator(EnemyFactory* enemyFactory);
            virtual ~RoomGenerator();
            Room *generateRoom(RoomType roomType, Location location);
            void set_min_max_monster_level(int min, int max);

        private:
            string generate_random_description();
            void add_random_monsters(Room* room);
            EnemyFactory* _enemy_factory;
            int _min_level = 1;
            int _max_level = 10;

            vector<string> _size_options = {
                "small",
                "medium sized",
                "big"
            };

            vector<string> _light_options = {
                "brightly lit",
                "moody lit",
                "dark"
            };

            vector<string> _clean_options = {
                "clean",
                "dirty",
                "disgusting"
            };
        };

    }
}

#endif //MINOR_CPP1_ROOMGENERATOR_HPP
