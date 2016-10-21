//
// Created by mafn on 10/21/16.
//

#ifndef MINOR_CPP1_COMMANDLINEINTERFACE_HPP
#define MINOR_CPP1_COMMANDLINEINTERFACE_HPP

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

namespace CLI {
    using std::string;
    using std::vector;
    using std::cout;
    using std::endl;
    using std::cin;

    class CommandLineInterface {
    public:
        string ask_for_options(string question, vector<string> options);
        string get_option(vector<string> options);

        void print_options(vector<string> options);
    };

}


#endif //MINOR_CPP1_COMMANDLINEINTERFACE_HPP