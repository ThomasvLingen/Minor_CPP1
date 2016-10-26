//
// Created by jazula on 10/24/16.
//

#include <stdexcept>
#include <iostream>
#include "FloorPlan.hpp"

#define i_left 0
#define i_right 1
#define i_down 2
#define i_up 3

namespace Dungeon
{
    namespace Generator
    {

        FloorPlan::FloorPlan(size_t height, size_t width)
        {
            if (height < 3 || width < 3) {
                throw std::invalid_argument("Height and width can not be smaller than 3!");
            }

            this->_height = height;
            this->_width = width;

            this->_plan.resize(height);
            for (size_t height_index = 0; height_index < height; height_index++) {
                this->_plan[height_index].resize(width);
                for (size_t width_index = 0; width_index < width; width_index++) {
                    this->_plan[height_index][width_index] = PlanRoomType::none;
                }
            }
        }

        FloorPlan::~FloorPlan()
        {}

        void FloorPlan::set_room(Location loc, PlanRoomType type)
        {
            if((size_t)loc.height_index < 0 || (size_t)loc.height_index > this->_height - 1
                || (size_t)loc.width_index < 0 || (size_t)loc.width_index > this->_width - 1){
                throw std::invalid_argument("Invalid location for room");
            }
            this->_plan[loc.height_index][loc.width_index] = type;
        }

        void FloorPlan::set_random_start_room()
        {
            int random_start_height_index = RANDOM.get_random_int(0, (int) this->_height - 1);
            int random_start_width_index = RANDOM.get_random_int(0, (int) this->_width - 1);

            this->_plan[random_start_height_index][random_start_width_index] = PlanRoomType::start;
            this->_start_room = {random_start_width_index, random_start_height_index};
        }

        void FloorPlan::generate_end_room_starting_from_start_room() //split this function
        {
            Location current_location = _start_room;
            Location new_location;
            Location target_end_room_location;
            Neighbours neighbours;
            std::vector<Location> created_rooms;

            int count = 1;
            int max_count = ((int) _height * (int) _width) / 5;

            while (count <= max_count) { //while loop, dont always want to raise count

                neighbours = get_open_neighbours(current_location);
                new_location = get_prefered_neighbour_loc(neighbours, current_location);

                if (compare_location(new_location, current_location)) {
                    current_location = created_rooms[RANDOM.get_random_int(0, created_rooms.size() - 1)];
                    continue;
                }

                set_room(new_location, PlanRoomType::normal);

                created_rooms.push_back(new_location);
                current_location = new_location;
                target_end_room_location = new_location;

                count++;
            }

            set_room(target_end_room_location, PlanRoomType::end);
            this->_end_room = target_end_room_location;
        }

        std::vector<int> FloorPlan::get_all_weights()
        {
            std::vector<int> weights;
            weights.resize(4, 10); //default weight

            if (_height > _width) {
                weights[i_up] += 10;
                weights[i_down] += 10;
            } else if (_height < _width) {
                weights[i_right] += 10;
                weights[i_left] += 10;
            }

            return weights;
        }

        FloorPlan::Neighbours FloorPlan::get_open_neighbours(Location location)
        {
            Neighbours possible_locations;
            Neighbours available_locations;

            possible_locations.insert(
                FloorPlan::Neighbour(
                    NeighbourSide::left,
                    {location.width_index - 1, location.height_index}
                )
            );

            possible_locations.insert(
                FloorPlan::Neighbour(
                    NeighbourSide::right,
                    {location.width_index + 1, location.height_index}
                )
            );

            possible_locations.insert(
                FloorPlan::Neighbour(
                    NeighbourSide::down,
                    {location.width_index, location.height_index - 1}
                )
            );

            possible_locations.insert(
                FloorPlan::Neighbour(
                    NeighbourSide::up,
                    {location.width_index, location.height_index + 1}
                )
            );

            for (Neighbour possible_loc: possible_locations) {
                if (is_open_location(possible_loc.second)) {
                    available_locations.insert(possible_loc);
                }
            }

            return available_locations;
        }

        bool FloorPlan::is_open_location(Location location)
        {
            if (!(location.height_index >= 0 && location.height_index < (int) this->_height)) {
                return false;
            }
            if (!(location.width_index >= 0 && location.width_index < (int) this->_width)) {
                return false;
            }
            if (!(this->_plan[location.height_index][location.width_index] == PlanRoomType::none)) {
                return false;
            }

            return true;
        }

        bool FloorPlan::compare_location(Location loc1, Location loc2)
        {
            if (loc1.height_index != loc2.height_index) {
                return false;
            }
            if (loc1.width_index != loc2.width_index) {
                return false;
            }

            return true;
        }

/// \param neighbours
/// \param current_location
/// \param target_location
/// \return returns current_location if no neighbours
        Location
        FloorPlan::get_prefered_neighbour_loc(FloorPlan::Neighbours neighbours, Location current_location)
        {
            if (neighbours.size() == 0) {
                return current_location;
            }

            std::vector<int> weights = get_all_weights();//current_location, target_location);

            int location = get_weighted_available_neighbour(neighbours, weights);

            switch (location) {
                case i_left: //left
                    return neighbours[NeighbourSide::left];
                case i_right: //right
                    return neighbours[NeighbourSide::right];
                case i_down: //down
                    return neighbours[NeighbourSide::down];
                case i_up: //up
                    return neighbours[NeighbourSide::up];
            }

            throw "unexpected";
        }


        int FloorPlan::get_weighted_available_neighbour(FloorPlan::Neighbours neighbours, std::vector<int> all_weights)
        {
            std::vector<int> weights;
            std::vector<int> return_values;
            for (Neighbour neighbour : neighbours) {
                switch (neighbour.first) {
                    case NeighbourSide::left :
                        return_values.push_back(i_left);
                        weights.push_back(all_weights[i_left]);
                        break;
                    case NeighbourSide::right :
                        return_values.push_back(i_right);
                        weights.push_back(all_weights[i_right]);
                        break;
                    case NeighbourSide::down :
                        return_values.push_back(i_down);
                        weights.push_back(all_weights[i_down]);
                        break;
                    case NeighbourSide::up :
                        return_values.push_back(i_up);
                        weights.push_back(all_weights[i_up]);
                        break;
                }
            }

            return RANDOM.get_weighted_int(weights, return_values);
        }

        FloorPlan::Plan FloorPlan::get_plan()
        {
            return _plan;
        }

    }
}