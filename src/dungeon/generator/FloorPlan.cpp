//
// Created by jazula on 10/24/16.
//
#include <stdexcept>
#include <iostream>
#include "FloorPlan.hpp"

namespace Dungeon
{
    namespace Generator
    {

        FloorPlan::FloorPlan(size_t height, size_t width, PlanRoomType start_room_type, PlanRoomType end_room_type)
        : _height(height)
        , _width(width)
        , _start_room_type(start_room_type)
        , _end_room_type(end_room_type)
        {
            if (height < 5 || width < 5) {
                throw std::invalid_argument("Height and width can not be smaller than 5!");
            }

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
            Location location = {random_start_width_index, random_start_height_index};

            this->set_room(location, this->_start_room_type);
            this->start_room = location;
        }

        void FloorPlan::generate_end_room_starting_from_start_room()
        {
            Location current_location = this->start_room; //perhaps get from argument
            Location new_location;

            int count = 1;
            int max_count = ((int) this->_height * (int) this->_width) / 3; //perhaps get from argument

            while (count <= max_count) { //while loop, dont always want to raise count
                new_location = get_prefered_neighbour_loc(current_location);

                if (new_location == current_location) {
                    current_location = _created_rooms[RANDOM.get_random_int(0, _created_rooms.size() - 1)];
                    continue;
                }

                set_room(new_location, PlanRoomType::normal);

                _created_rooms.push_back(new_location);
                current_location = new_location;
                count++;
            }
            set_end_room(_created_rooms);
        }

        vector<int> FloorPlan::get_all_weights()
        {
            vector<int> weights;
            weights.resize(4, 10); //default weight

            if (this->_height > this->_width) {
                weights[_neighbour_side_to_int[NeighbourSide::up]] += 10;
                weights[_neighbour_side_to_int[NeighbourSide::down]]  += 10;
            } else if (this->_height < this->_width) {
                weights[_neighbour_side_to_int[NeighbourSide::right]]  += 10;
                weights[_neighbour_side_to_int[NeighbourSide::left]] += 10;
            }

            return weights;
        }

        FloorPlan::Neighbours FloorPlan::get_open_neighbours(Location location)
        {
            Neighbours possible_locations;
            Neighbours available_locations;

            for(auto& side_to_difference : _neighbour_side_to_width_height_difference){
                possible_locations.insert(
                    FloorPlan::Neighbour(
                        side_to_difference.first,
                        {location.width_index + side_to_difference.second.first,
                        location.height_index + side_to_difference.second.second}
                    )
                );
            }

            for (auto& possible_loc: possible_locations) {
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

/// \param neighbours
/// \param current_location
/// \param target_location
/// \return returns current_location if no neighbours, otherwise a neighbour location
        Location FloorPlan::get_prefered_neighbour_loc(Location current_location)
        {
            FloorPlan::Neighbours neighbours = get_open_neighbours(current_location);
            if (neighbours.size() == 0) {
                return current_location;
            }

            vector<int> weights = get_all_weights();//current_location, target_location);

            int location = get_weighted_available_neighbour(neighbours, weights);

            return neighbours[this->_int_to_neighbour_side[location]];
        }


        int FloorPlan::get_weighted_available_neighbour(FloorPlan::Neighbours neighbours, vector<int> all_weights)
        {
            vector<int> weights;
            vector<int> return_values;

            for (auto& neighbour : neighbours) {
                int side_index = this->_neighbour_side_to_int[neighbour.first];
                return_values.push_back(side_index);
                weights.push_back(all_weights[side_index]);
            }

            return RANDOM.get_weighted_int(weights, return_values);
        }

        FloorPlan::Plan FloorPlan::get_plan()
        {
            return this->_plan;
        }

        size_t FloorPlan::get_height()
        {
            return this->_height;
        }

        size_t FloorPlan::get_width()
        {
            return this->_width;
        }

        void FloorPlan::set_end_room(vector<Location> &possible_locations)
        {
            Location location = possible_locations[RANDOM.get_random_int(0, possible_locations.size() - 1)];
            set_room(location, this->_end_room_type);
            this->end_room = location;
        }

        void FloorPlan::set_start_room(Location location)
        {
            this->set_room(location, this->_start_room_type);
            this->start_room = location;
        }

    }
}