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
        Dungeon(vector<Floor *> floors);
        virtual ~Dungeon();

        vector<Floor *> floors;

    private:

    };
}

#endif //MINOR_CPP1_DUNGEON_HPP
