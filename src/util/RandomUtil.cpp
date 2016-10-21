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

    int RandomUtil::get_weighted_int(std::vector<int> weights)
    {
        int sum_of_weights = 0;

        for(int num : weights){
            sum_of_weights += num;
        }

        int random = this->get_random_int(0, sum_of_weights);

        for(int index = 0; index < (int)weights.size(); index++){
            if(random < weights[index]){
                return index;
            }
            random -= weights[index];
        }

        return 0; //random number was 0
    }

    ///
    /// \param percentage_to_succeed percentage from 0 to 100 to return true
    /// \return
    bool RandomUtil::weighted_coin_toss(int percentage_to_succeed)
    {
        int result;

        std::vector<int> weight;
        weight.push_back(percentage_to_succeed);
        weight.push_back(100 - percentage_to_succeed);

        result = this->get_weighted_int(weight);

        if(result == 0){
            return true;
        } else if (result == 1) {
            return false;
        } else {
            throw "weighted_coin_toss return something else then 1 or 0";
        }
    }

    RandomUtil& RandomUtil::get_instance()
    {
        static RandomUtil randomUtil;
        return randomUtil;
    }
}