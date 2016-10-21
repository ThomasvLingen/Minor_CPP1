//
// Created by mafn on 10/21/16.
//

#include "CommandLineInterface.hpp"
#include "util/StrUtil.hpp"

namespace CLI {

    string CommandLineInterface::ask_for_options(string question, vector<string> options)
    {
        cout << question << endl << endl;

        this->print_options(options);

        return this->get_option(options);
    }

    void CommandLineInterface::print_options(vector<string> options)
    {
        for (int i = 0; i < options.size(); i++) {
            cout << i << " " << options[i] << endl;
        }
    }

    string CommandLineInterface::get_option(vector<string> options)
    {
        string current_answer = "";
        bool current_answer_is_valid = false;

        while(!current_answer_is_valid) {
            std::getline(cin, current_answer);

            current_answer_is_valid = Util::StrUtil::vector_contains_string(options, current_answer);

            if (!current_answer_is_valid) {
                cout << "Invalid input" << endl;
            }
        }

        return current_answer;
    }

    string CommandLineInterface::ask_for_options(OptionsQuestion options)
    {
        return this->ask_for_options(options.question, options.options);
    }
}
