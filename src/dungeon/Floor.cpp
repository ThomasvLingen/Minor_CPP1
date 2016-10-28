//
// Created by jazula on 10/17/16.
//

#include <iostream>
#include <stdexcept>
#include "Floor.hpp"

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

    void Floor::print_raw_map()
    {
        for (size_t height_index = 0; height_index < _height; height_index++) {
            vector<Room*>& row = _map[height_index];
            print_row(row);

            cout << endl;

            if(height_index + 1 < _height){
                vector<Room*>& next_row = _map[height_index + 1];
                print_vertical_tunnels(row, next_row);
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
        if((size_t)location.width_index < 0 || (size_t)location.width_index > this->_width - 1
           || (size_t)location.height_index < 0 || (size_t)location.height_index > this->_height - 1){

            throw std::invalid_argument("Location is not valid");
        }
    }

    void Floor::set_level_range(level_range range)
    {
        this->_level_range = range;
    }

    char Floor::get_room_print_char(Room *room)
    {
        if (room == nullptr) {
            return '.';
        } else {
            return this->_room_type_to_char[room->room_type];
        }
    }

    bool Floor::are_rooms_connected(Room *current_room, Room *next_room)
    {
        if(next_room != nullptr && current_room != nullptr){
            return (current_room->is_discovered() || next_room->is_discovered());
        }else {
            return false;
        }
    }

    void Floor::print_row(vector<Room *> &row)
    {
        for (size_t width_index = 0; width_index < _width; width_index++) {
            Room* room = row[width_index];

            cout << get_room_print_char(room);
            if(width_index + 1 < _width) {
                Room* next_room = row[width_index + 1];

                if(are_rooms_connected(room, next_room)){
                    cout << "--";
                } else {
                    cout << "  ";
                }

            }

        }
    }

    void Floor::print_vertical_tunnels(vector<Room *> &current_row, vector<Room *> &next_row)
    {
        for (size_t width_index = 0; width_index < _width; width_index++){
            bool connected = are_rooms_connected(current_row[width_index], next_row[width_index]);
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

}