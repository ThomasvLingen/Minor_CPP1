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
        using std::map;
        using std::pair;
        using std::vector;

        enum PlanRoomType {
            none, start, normal, end
        };
        enum NeighbourSide {
            left, right, up, down
        };

        class FloorPlan {
        public:
            typedef vector<vector<PlanRoomType>> Plan;

        public:
            FloorPlan(size_t height, size_t width);
            virtual ~FloorPlan();
            void set_random_start_room();
            void generate_end_room_starting_from_start_room();
            Plan get_plan();
            size_t get_height();
            size_t get_width();

        private:
            typedef map<NeighbourSide, Location> Neighbours;
            typedef pair<NeighbourSide, Location> Neighbour;

            Plan _plan;
            size_t _height;
            size_t _width;
            Location _start_room;
            Location _end_room;
            map<NeighbourSide, int> _neighbour_side_to_int = {
                {NeighbourSide::left, 0},
                {NeighbourSide::right, 1},
                {NeighbourSide::down, 2},
                {NeighbourSide::up, 3}
            };

            map<int, NeighbourSide> _int_to_neighbour_side = {
                {0, NeighbourSide::left},
                {1, NeighbourSide::right},
                {2, NeighbourSide::down},
                {3, NeighbourSide::up}
            };

            map<NeighbourSide, pair<int, int>> _neighbour_side_to_width_height_difference = { //pair: width | height
                {NeighbourSide::left,   {-1, 0}},
                {NeighbourSide::right,  {+1, 0}},
                {NeighbourSide::down,   {0, -1}},
                {NeighbourSide::up,     {0, +1}}
            };

            vector<int> get_all_weights();
            map<NeighbourSide, Location> get_open_neighbours(Location location);
            bool is_open_location(Location location);
            Location get_prefered_neighbour_loc(Location current_location);
            int get_weighted_available_neighbour(Neighbours neighbours, vector<int> all_weights);
            void set_room(Location loc, PlanRoomType type);
            void set_end_room(vector<Location> &possible_locations);

        };

    }
}

#endif //MINOR_CPP1_FLOORPLAN_HPP
