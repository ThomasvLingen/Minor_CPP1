//
// Created by jazula on 10/17/16.
//

#ifndef MINOR_CPP1_FLOORGENERATOR_HPP
#define MINOR_CPP1_FLOORGENERATOR_HPP

#include <dungeon/Dungeon.hpp>
#include "dungeon/Floor.hpp"
#include "util/RandomUtil.hpp"
#include "FloorPlan.hpp"
#include "RoomGenerator.hpp"

namespace Dungeon
{
    namespace Generator
    {
        using std::map;
        using std::size_t;

        class FloorGenerator {
        public:
            FloorGenerator(EnemyFactory* enemyFactory, ItemFactory* itemFactory);
            virtual ~FloorGenerator();
            Floor* generate_floor(size_t height, size_t width, RoomType start_room_type, RoomType end_room_type);
            void set_dungeon(::Dungeon::Dungeon* dungeon);

        private:
            ::Dungeon::Dungeon* _dungeon;
            map<PlanRoomType, RoomType> _plan_room_type_to_room_type_map = {
                {PlanRoomType::normal, RoomType::normal},
                {PlanRoomType::start, RoomType::start},
                {PlanRoomType::end, RoomType::end},
                {PlanRoomType::stair_up, RoomType::stair_up},
                {PlanRoomType::stair_down, RoomType::stair_down},
                {PlanRoomType::boss, RoomType::boss}
            };

            map<RoomType, PlanRoomType> _room_type_to_plan_room_type_map = {
                {RoomType::normal, PlanRoomType::normal},
                {RoomType::start, PlanRoomType::start},
                {RoomType::end, PlanRoomType::end},
                {RoomType::stair_up, PlanRoomType::stair_up},
                {RoomType::stair_down, PlanRoomType::stair_down},
                {RoomType::boss, PlanRoomType::boss}
            };
            RoomGenerator _room_generator;
            Floor* _convert_floor_plan_to_floor(FloorPlan* floor_plan);
            Room* convert_type_location_to_room(size_t width, size_t height, PlanRoomType type, Floor& container_floor);
        };

    }
}

#endif //MINOR_CPP1_FLOORGENERATOR_HPP
