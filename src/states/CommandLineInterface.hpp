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
    using std::stoi;

    struct OptionsQuestion {
        string question;
        vector<string> options;
    };

    struct NumberQuestion {
        string question;
        int min;
        int max;
    };

    class CommandLineInterface {
    public:
        string ask_for_options(string question, vector<string> options);
        string ask_for_options(OptionsQuestion options);
        string ask_for_string(string question);

        int ask_for_number(string question, int min, int max);
        int ask_for_number(NumberQuestion number_question);

        bool ask_for_yes_no(string question);
    private:
        vector<string> _valid_yes_no_answers = {"yes", "y", "no", "n"};
        vector<string> _valid_yes = {"yes", "y"};
        vector<string> _valid_no = {"no", "n"};

        void _print_options(vector<string> options);
        string _get_option(vector<string> options);
        bool _is_valid_yes_no(string answer);
    };

}


#endif //MINOR_CPP1_COMMANDLINEINTERFACE_HPP