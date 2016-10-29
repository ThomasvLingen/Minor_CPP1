//
// Created by jazula on 10/17/16.
//

#include <iostream>
#include <stdexcept>
#include "Floor.hpp"
#include "Dungeon.hpp"

namespace Dungeon
{
    using std::cout;
    using std::endl;

    Floor::Floor(size_t height, size_t width)
    : _height(height)
    , _width(width)
    {
        this->_map.reserve(height);
        for (size_t index = 0; index < height; index++) {
            _map.push_back(vector<Room *>());
            _map[index].resize(width);
        }
    }

    Floor::~Floor()
    {
        for (vector<Room *> room_vector : _map) {
            for (Room *room : room_vector) {
                delete room;
            }
        }
    }

    void Floor::set_room(Room *room_ptr)
    {
        check_location(room_ptr->location);

        this->_map[room_ptr->location.height_index][room_ptr->location.width_index] = room_ptr;
    }

    Room *Floor::get_room(Location location)
    {
        check_location(location);

        return this->_map[location.height_index][location.width_index];
    }

    void Floor::print_floor()
    {
        print_floor(false);
    }

    void Floor::print_floor(bool god_mode)
    {
        for (size_t height_index = 0; height_index < _height; height_index++) {
            vector<Room*>& row = _map[height_index];
            print_row(row, god_mode);
            cout << endl;

            if(height_index + 1 < _height){
                vector<Room*>& next_row = _map[height_index + 1];
                print_vertical_tunnels(row, next_row, god_mode);
            }

            cout << endl;
        }
    }

    size_t Floor::get_width()
    {
        return this->_width;
    }

    size_t Floor::get_height()
    {
        return this->_height;
    }

    void Floor::check_location(Location location)
    {
        if(!valid_location(location)){
            throw std::invalid_argument("Location is not valid");
        }
    }

    void Floor::set_level_range(level_range range)
    {
        this->monster_level_range = range;
    }

    char Floor::get_room_print_char(Room *room, bool god_mode)
    {
        if (room != nullptr) {
            if(room->is_discovered() || god_mode){
                return this->_room_type_to_char[room->room_type];
            }
        }
        return '.';
    }

    bool Floor::should_draw_tunnel_between_rooms(Room *current_room, Room *next_room, bool god_mode)
    {
        if(next_room != nullptr && current_room != nullptr){
            if(god_mode){
                return true;
            } else {
                return (current_room->is_discovered() || next_room->is_discovered());
            }
        }else {
            return false;
        }
    }

    void Floor::print_row(vector<Room *> &row, bool god_mode)
    {
        for (size_t width_index = 0; width_index < _width; width_index++) {
            Room* room = row[width_index];

            cout << get_room_print_char(room, god_mode);

            if(width_index + 1 < _width) {
                Room* next_room = row[width_index + 1];

                if(should_draw_tunnel_between_rooms(room, next_room, god_mode)){
                    cout << "--";
                } else {
                    cout << "  ";
                }

            }

        }
    }

    void Floor::print_vertical_tunnels(vector<Room *> &current_row, vector<Room *> &next_row, bool god_mode)
    {
        for (size_t width_index = 0; width_index < _width; width_index++){
            bool connected = should_draw_tunnel_between_rooms(current_row[width_index], next_row[width_index], god_mode);
            if(connected){
                cout << "|";
            } else {
                cout << " ";
            }

            if(width_index + 1 < _width){
                cout << "  ";
            }
        }
    }

    bool Floor::valid_location(Location location)
    {
        if((size_t)location.width_index < 0 || (size_t)location.width_index > this->_width - 1
           || (size_t)location.height_index < 0 || (size_t)location.height_index > this->_height - 1){

            return false;
        }
        return true;
    }

    Room *Floor::get_room_in_direction(Room *current_room, Direction direction)
    {
        Location new_location = this->get_new_location_in_direction(direction, current_room->location);

        if (this->valid_location(new_location)) {
            return this->get_room(new_location);
        } else {
            return nullptr;
        }
    }

    Location Floor::get_new_location_in_direction(Direction direction, Location location)
    {
        int width_delta  = _direction_to_location_delta[direction].first;
        int height_delta = _direction_to_location_delta[direction].second;

        return Location {
            location.width_index + width_delta,
            location.height_index + height_delta
        };
    }

    vector<Direction> Floor::get_available_directions(Room* room)
    {
        vector<Direction> available_directions;

        for(Direction direction : this->_available_directions){
            Room* neighbour_room = get_room_in_direction(room, direction);
            if(neighbour_room != nullptr){
                available_directions.push_back(direction);
            }
        }

        return available_directions;
    }

    Floor* Floor::get_floor(Room* room)
    {
        // op room type, kan je bepalen wat je moet doen, als het een normal room is, gewoon this returnen.
        switch(room->room_type){
            case stair_up:
                return this->dungeon->get_prev_floor(this);
            case stair_down:
                return this->dungeon->get_next_floor(this);
            default:
                return this;
        }
    }

}