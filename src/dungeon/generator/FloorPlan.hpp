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


class FloorPlan {
    enum Type {none, start, normal, end};
    enum Side {left, right, up, down};
    typedef Room::Location Loc;

public:
    typedef std::vector<std::vector<Type>> Plan;

public:
    FloorPlan(size_t height, size_t width);
    virtual ~FloorPlan();

    void set_random_start_room();
    void generate_end_room_starting_from_start_room();
    Floor* generate_floor_from_plan();
    Plan get_plan();

private:
    typedef std::map<FloorPlan::Side, Loc> Neighbours;
    typedef std::pair<FloorPlan::Side, Loc> Neighbour;

    Plan _plan;
    size_t _height;
    size_t _width;
    Loc _start_room;
    Loc _end_room;

    std::vector<int> get_all_weights();//FloorPlan::Loc current_location, FloorPlan::Loc target_location);
    std::map<FloorPlan::Side , Loc> get_open_neighbours(Loc location);
    bool is_open_location(Loc location);
    bool compare_location(Loc loc1, Loc loc2);
    Room::RoomType convert_floorplan_type_to_room_type(FloorPlan::Type floorplan_type);
    Loc get_prefered_neighbour_loc(Neighbours neighbours, Loc current_location);
    int get_weighted_available_neighbour(Neighbours neighbours, std::vector<int> all_weights);
    void set_room(FloorPlan::Loc loc, FloorPlan::Type type);
};


#endif //MINOR_CPP1_FLOORPLAN_HPP
