//
// Created by jazula on 10/17/16.
//

#ifndef MINOR_CPP1_DUNGEON_HPP
#define MINOR_CPP1_DUNGEON_HPP


#include <vector>
#include "Floor.hpp"

namespace Dungeon
{
    using std::vector;

    struct DungeonDimensions {
        size_t width;
        size_t height;
        size_t floors;
    };

    class Dungeon {
    public:
        Dungeon();
        virtual ~Dungeon();

        vector<Floor *> floors;

        void add_floor(Floor* floor);
        Floor* get_next_floor(Floor* current_floor);
        Floor* get_prev_floor(Floor* current_floor);
        size_t get_floor_index(Floor* floor);

    private:

    };
}

#endif //MINOR_CPP1_DUNGEON_HPP
