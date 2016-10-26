//
// Created by jazula on 10/24/16.
//

#ifndef MINOR_CPP1_FLOORPLAN_HPP
#define MINOR_CPP1_FLOORPLAN_HPP

#include <vector>
#include <map>
#include "dungeon/Floor.hpp"
#include "../Room.hpp"
#include "util/RandomUtil.hpp"

namespace Dungeon
{
    namespace Generator
    {
        enum PlanRoomType {
            none, start, normal, end
        };
        enum NeighbourSide {
            left, right, up, down
        };

        class FloorPlan {
        public:
            typedef std::vector<std::vector<PlanRoomType>> Plan;

        public:
            FloorPlan(size_t height, size_t width);
            virtual ~FloorPlan();
            void set_random_start_room();
            void generate_end_room_starting_from_start_room();
            Plan get_plan();

        private:
            typedef std::map<NeighbourSide, Location> Neighbours;
            typedef std::pair<NeighbourSide, Location> Neighbour;

            Plan _plan;
            size_t _height;
            size_t _width;
            Location _start_room;
            Location _end_room;

            std::vector<int> get_all_weights();//FloorPlan::Loc current_location, FloorPlan::Loc target_location);
            std::map<NeighbourSide, Location> get_open_neighbours(Location location);
            bool is_open_location(Location location);
            bool compare_location(Location loc1, Location loc2);
            Location get_prefered_neighbour_loc(Neighbours neighbours, Location current_location);
            int get_weighted_available_neighbour(Neighbours neighbours, std::vector<int> all_weights);
            void set_room(Location loc, PlanRoomType type);

        };

    }
}

#endif //MINOR_CPP1_FLOORPLAN_HPP
