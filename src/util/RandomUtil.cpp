//
// Created by jazula on 10/20/16.
//

#include <iostream>
#include "RandomUtil.hpp"

namespace Util
{
    RandomUtil::RandomUtil()
    {
        _generator.seed(time(0));
        std::cout << "seeded!" << std::endl;
    }

    int RandomUtil::get_random_int(int min_range, int max_range)
    {
        std::uniform_int_distribution<int> distribution(min_range, max_range);
        return distribution(this->_generator);
    }
}