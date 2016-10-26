//
// Created by jazula on 10/17/16.
//

#ifndef MINOR_CPP1_FLOORGENERATOR_HPP
#define MINOR_CPP1_FLOORGENERATOR_HPP

#include "dungeon/Floor.hpp"
#include "util/RandomUtil.hpp"
#include "FloorPlan.hpp"

namespace Dungeon
{
    namespace Generator
    {

        class FloorGenerator {
        public:
            FloorGenerator();

            virtual ~FloorGenerator();

            Floor *generate_floor(std::size_t height, std::size_t width);
        };

    }
}

#endif //MINOR_CPP1_FLOORGENERATOR_HPP
