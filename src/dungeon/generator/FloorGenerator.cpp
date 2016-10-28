//
// Created by jazula on 10/17/16.
//

#include "FloorGenerator.hpp"
#include "FloorPlan.hpp"
#include <algorithm>
#include <iostream>

namespace Dungeon
{
    namespace Generator
    {
        using std::vector;
        using std::cout;
        using std::endl;

        FloorGenerator::FloorGenerator(EnemyFactory* enemyFactory, ItemFactory* itemFactory)
        : _room_generator(enemyFactory, itemFactory)
        {
        }

        FloorGenerator::~FloorGenerator()
        {}

        Floor *FloorGenerator::generate_floor(size_t height, size_t width, RoomType start_room_type, RoomType end_room_type)
        {
            PlanRoomType start_room_plan_type = this->_room_type_to_plan_room_type_map[start_room_type];
            PlanRoomType end_room_plan_type   = this->_room_type_to_plan_room_type_map[end_room_type];
            FloorPlan* floorPlan = nullptr;
            Floor* new_floor = nullptr;

            try {
                floorPlan = new FloorPlan(height, width, start_room_plan_type, end_room_plan_type);
            } catch(std::exception &exception) {
                cout << exception.what() << endl;
                return nullptr;
            }

            try {
                floorPlan->set_random_start_room();
            } catch(std::exception &exception) {
                cout << "Failed to set a start room::" << endl << "\t";
                cout << exception.what() << endl;
                floorPlan->set_start_room({0,0});
                cout << endl << "Setting 0,0 as starting room" << endl;
            }

            try {
                floorPlan->generate_end_room_starting_from_start_room();
            } catch (std::exception &exception) {
                cout << "Failed to generate end room:" << endl << "\t";
                cout << exception.what() << endl;
                return nullptr;
            }

            try {
                new_floor = this->_convert_floor_plan_to_floor(floorPlan);
            } catch (std::exception &exception) {
                cout << "Failed to convert floorplan to floor:" << endl << "\t";
                cout << exception.what() << endl;
                return nullptr;
            }

            delete(floorPlan);
            return new_floor;
        }

        Floor *FloorGenerator::_convert_floor_plan_to_floor(FloorPlan* fp)
        {
            int height_index = 0;
            int width_index = 0;
            Floor *floor = new Floor(fp->get_height(), fp->get_width());
            for (vector<PlanRoomType> row: fp->get_plan()) {
                for (PlanRoomType type: row) {
                    if (type != PlanRoomType::none) {
                        Room *room = convert_type_location_to_room(width_index, height_index, type);
                        floor->set_room(room);
                    }
                    width_index++;
                }
                height_index++;
                width_index = 0;
            }

            return floor;
        }

        Room *FloorGenerator::convert_type_location_to_room(size_t width, size_t height, PlanRoomType type)
        {
            Room *room = _room_generator.generateRoom(
                _plan_room_type_to_room_type_map[type],
                {(int)width, (int)height}
            );
            return room;
        }

    }
}