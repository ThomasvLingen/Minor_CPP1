//
// Created by jazula on 10/20/16.
//

#ifndef MINOR_CPP1_RANDOMUTIL_HPP
#define MINOR_CPP1_RANDOMUTIL_HPP

#include <random>
#include <ctime>

namespace Util
{
    class RandomUtil {

    public:
        RandomUtil();

        int get_random_int(int min_range, int max_range);

    private:
        std::default_random_engine _generator;

    };
}


#endif //MINOR_CPP1_RANDOMUTIL_HPP
