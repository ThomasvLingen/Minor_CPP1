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
    static Room::Location setStartAndEndRoom(Floor* floor, std::size_t height, std::size_t width);
    static int getRandomRoomNumber(std::size_t width);
    static std::vector<Room::Location> createNeighbours(Floor* floor, std::vector<Room::Location> roomList);
    static void setRoomInFloor(Floor* floor, Room* room);
    static std::vector<Room::Location> getOpenNeighbours(Floor* floor, Room::Location location);
    static std::vector<Room::Location> getRawNeighbours(Room::Location location); //does not check if valid
    static bool isAvailableRoom(Floor* floor, Room::Location location);
    static std::set<int> getRandomIntsInRange(int max_range);



};


#endif //MINOR_CPP1_FLOORGENERATOR_HPP
