//
// Created by jazula on 10/17/16.
//

#include "FloorGenerator.hpp"
#include <algorithm>

FloorGenerator::FloorGenerator()
{}

FloorGenerator::~FloorGenerator()
{}

Floor *FloorGenerator::generateFloor(std::size_t height, std::size_t width)
{
    Room::Location start_room_location;
    Floor *new_floor = new Floor(height, width);
    start_room_location = setStartAndEndRoom(new_floor, height, width);

    std::vector<Room::Location> room_list;
    room_list.push_back(start_room_location);
    for (int index = 0; index < 5; index++) {
        room_list = createNeighbours(new_floor, room_list);//create the neighbours using the create neighbour function
    }

    return new_floor;
}

Room::Location FloorGenerator::setStartAndEndRoom(Floor *floor, std::size_t height, std::size_t width)
{
    Room *start_room = new Room();
    start_room->location = {
        .width_index = getRandomRoomNumber(width),
        .height_index = 0 //start room always on first row
    };
    start_room->room_type = Room::start;

    Room *end_room = new Room();
    end_room->location = {
        .width_index = getRandomRoomNumber(width),
        .height_index = (int) height - 1 //end room always on last row
    };
    end_room->room_type = Room::end;

    setRoomInFloor(floor, start_room);
    setRoomInFloor(floor, end_room);

    return start_room->location;
}

int FloorGenerator::getRandomRoomNumber(std::size_t width)
{
    static bool seeded = false;
    if (!seeded) {
        std::srand((uint) time(NULL)); //seed
        seeded = true;
    }
    return (std::rand() % (int) width);
}

std::set<int> FloorGenerator::getRandomIntsInRange(int max_range)
{
    std::set<int> indexes;
    static bool seeded = false;
    if (!seeded) {
        std::srand((uint) time(NULL)); //seed
        seeded = true;
    }

    int amount = std::rand() % (max_range + 1);

    for (int index = 0; index <= amount; index++) {
        while (indexes.insert((int) std::rand() % (max_range + 1)).second == false); //IF EVERYTHING HANGS LOOK HERE
        // this should not loop forever, since no more numbers can be added then available
    }
    return indexes;
}

std::vector<Room::Location> FloorGenerator::createNeighbours(Floor *floor, std::vector<Room::Location> roomList)
{
    std::vector<Room::Location> created_room_locations;

    for (Room::Location location : roomList) {
        /* check amount of neighbours available
         * create random neighbours from 0 to available
         * start room must always have one neighbour, perhaps call function again when room location return list is empty
         * return new neighbours locations
         * */
        std::vector<Room::Location> neighbourLocations = getOpenNeighbours(floor, location);
        std::set<int> indexes = getRandomIntsInRange((int) neighbourLocations.size() - 1);

        for (int index : indexes) {
            Room *new_room = new Room();
            new_room->room_type = Room::normal;
            new_room->location = neighbourLocations[index];
            created_room_locations.push_back(new_room->location);
            setRoomInFloor(floor, new_room);
        }

    }
    return created_room_locations;
}

void FloorGenerator::setRoomInFloor(Floor *floor, Room *room)
//setRoom will be subject to change, placed in func to change easy
{
    floor->setRoom(
        room->location,
        room
    );
}

std::vector<Room::Location> FloorGenerator::getOpenNeighbours(Floor *floor, Room::Location location)
{
    std::vector<Room::Location> open_neighbours;
    std::vector<Room::Location> raw_neighbours = getRawNeighbours(location);

    for (Room::Location neighbourLocation : raw_neighbours) {
        if (isAvailableRoom(floor, neighbourLocation)) {
            open_neighbours.push_back(neighbourLocation);
        }
    }

    return open_neighbours;
}

inline Room::Location getNewLocation(Room::Location old_location, int width_steps, int height_steps)
{
    return Room::Location {
        .width_index  = old_location.width_index + width_steps,
        .height_index = old_location.height_index + height_steps
    };
}

std::vector<Room::Location> FloorGenerator::getRawNeighbours(Room::Location location)
{
    std::vector<Room::Location> neighbour_locations;

    neighbour_locations.push_back(getNewLocation(location, -1, 0));
    neighbour_locations.push_back(getNewLocation(location, +1, 0));
    neighbour_locations.push_back(getNewLocation(location, 0, -1));
    neighbour_locations.push_back(getNewLocation(location, 0, +1));

    return neighbour_locations;
}

bool FloorGenerator::isAvailableRoom(Floor *floor, Room::Location location)
{
    if (location.width_index >= (int) floor->_width || location.width_index < 0) {
        //width is a count, width_index goes from 0 to count-1
        return false;
    } else if (location.height_index >= (int) floor->_height || location.height_index < 0) {
        return false;
    } else if (floor->getRoom(location) != nullptr) {
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

