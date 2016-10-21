//
// Created by jazula on 10/17/16.
//

#ifndef MINOR_CPP1_FLOORGENERATOR_HPP
#define MINOR_CPP1_FLOORGENERATOR_HPP


#include <dungeon/Floor.hpp>
#include <set>

class FloorGenerator {
public:
    FloorGenerator();
    virtual ~FloorGenerator();

    static Floor* generateFloor(std::size_t height, std::size_t width);

private:
    static Room::Location set_start_and_end_room(Floor *floor, std::size_t height, std::size_t width);
    static int get_random_room_index(std::size_t width);
    static std::vector<Room::Location> create_neighbours(Floor *floor, std::vector<Room::Location> room_list);
    static void set_room_in_floor(Floor *floor, Room *room);
    static std::vector<Room::Location> get_open_neighbours(Floor *floor, Room::Location location);
    static std::vector<Room::Location> get_raw_neighbours(Room::Location location); //does not check if valid
    static bool is_available(Floor *floor, Room::Location location);
    static std::set<int> get_random_ints_in_range(int max_range);
    static std::vector<int> get_random_gen_weights(int range);
    static int get_weighted_int(int range);

};


#endif //MINOR_CPP1_FLOORGENERATOR_HPP
