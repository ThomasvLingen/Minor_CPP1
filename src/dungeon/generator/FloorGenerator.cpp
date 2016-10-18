//
// Created by jazula on 10/17/16.
//

#include "FloorGenerator.hpp"
#include <algorithm>
#include <set>

FloorGenerator::FloorGenerator()
{}

FloorGenerator::~FloorGenerator()
{}

Floor* FloorGenerator::generateFloor(std::size_t height, std::size_t width)
{
    Floor* new_floor = new Floor(height, width);
    setStartAndEndRoom(new_floor, height, width);
    //create the neighbours using the create neighbour function

    return new_floor;
}

void FloorGenerator::setStartAndEndRoom(Floor* floor, std::size_t height, std::size_t width)
{
    Room* start_room = new Room();
    start_room->location = {
            .width_index = getRandomRoomNumber(width),
            .height_index = 0 //start room always on first row
    };
    start_room->room_type = Room::start;

    Room* end_room = new Room();
    end_room->location = {
            .width_index = getRandomRoomNumber(width),
            .height_index = (int)height - 1 //end room always on last row
    };
    end_room->room_type = Room::end;

    setRoomInFloor(floor, start_room);
    setRoomInFloor(floor, end_room);
}

int FloorGenerator::getRandomRoomNumber(std::size_t width)
{
    std::srand((uint)time(NULL)); //seed
    return (std::rand() % (int)width);
}

inline std::set<int> getRandomIntsInRange(int max_range){
    std::set<int> indexes;
    std::srand((uint)time(NULL)); //seed

    for(int index = 0; index <= std::rand() % (max_range + 1); index++){
        while (indexes.insert((int)std::rand() % (max_range + 1)).second == false ); //IF EVERYTHING HANGS LOOK HERE
        // this should not loop forever, since no more numbers can be added then available
    }
    return indexes;
}

std::vector<Room::Location> FloorGenerator::createNeighbours(Floor *floor, std::vector<Room::Location> roomList)
{
    std::vector<Room::Location> createdRoomsLocations;

    for(Room::Location location : roomList){
        /* check amount of neighbours available
         * create random neighbours from 0 to available
         * start room must always have one neighbour, perhaps call function again when room location return list is empty
         * return new neighbours locations
         * */
        std::vector<Room::Location> neighbourLocations = getOpenNeighbours(floor, location);
        std::set<int> indexes = getRandomIntsInRange((int)roomList.size() - 1);

        for(int index : indexes){
            Room* new_room = new Room();
            new_room->location = neighbourLocations[index];
            createdRoomsLocations.push_back(new_room->location);
            setRoomInFloor(floor, new_room);
        }

    }
    return createdRoomsLocations;
}

void FloorGenerator::setRoomInFloor(Floor *floor, Room *room) //setRoom will be subject to change, placed in func to change easy
{
    floor->setRoom(
            room->location,
            room
    );
}

std::vector<Room::Location> FloorGenerator::getOpenNeighbours(Floor* floor, Room::Location location)
{
    std::vector<Room::Location> openNeighbours;
    std::vector<Room::Location> rawNeighbours = getRawNeighbours(location);

    for(Room::Location neighbourLocation : rawNeighbours){
        if(isAvailableRoom(floor, neighbourLocation)){
            openNeighbours.push_back(neighbourLocation);
        }
    }

    return openNeighbours;
}

inline Room::Location getNewLocation(Room::Location old_location, int width_steps, int height_steps){
    return Room::Location {
            .width_index  = old_location.width_index  + width_steps,
            .height_index = old_location.height_index + height_steps
    };
}

std::vector<Room::Location> FloorGenerator::getRawNeighbours(Room::Location location)
{
    std::vector<Room::Location> neighbourLocations;

    neighbourLocations.push_back(getNewLocation(location, -1, -1));
    neighbourLocations.push_back(getNewLocation(location, -1, +1));
    neighbourLocations.push_back(getNewLocation(location, +1, -1));
    neighbourLocations.push_back(getNewLocation(location, +1, +1));

    return neighbourLocations;
}

bool FloorGenerator::isAvailableRoom(Floor *floor, Room::Location location)
{
    if(location.width_index >= (int)floor->_width){ //width is a count, width index goes from 0 to count-1
        return false;
    }
    else if(location.height_index >= (int)floor->_height){
        return false;
    }
    else if(floor->getRoom(location) != nullptr){
        return false;
    }
    return true;
}



/* functie voor pad maken
 * begin bij start room, maak random aantal rooms er langs (check of dit kan)
 * laat deze functie returnen welke nieuwe rooms hij aanmaakt en roep daar de functie weer op aan
 *
 * random idee van iets wat niet meer nuttig is: sla in een dict op welke rooms je al hebt gehad
 * */

