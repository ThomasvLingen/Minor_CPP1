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

        return Util::StrUtil::to_lower(this->get_option(options));
    }

    string CommandLineInterface::ask_for_string(string question)
    {
        cout << question << endl << endl;

        string current_answer = "";
        bool current_answer_is_valid = false;

        while (!current_answer_is_valid) {
            cout << "> ";
            std::getline(cin, current_answer);

            current_answer_is_valid = current_answer != "";

            if (!current_answer_is_valid) {
                cout << "Invalid input" << endl;
            }
        }

        return current_answer;
    }

    void CommandLineInterface::print_options(vector<string> options)
    {
        for (uint i = 0; i < options.size(); i++) {
            cout << i << " " << options[i] << endl;
        }
    }

    string CommandLineInterface::get_option(vector<string> options)
    {
        string current_answer = "";
        bool current_answer_is_valid = false;

        while(!current_answer_is_valid) {
            cout << "> ";
            std::getline(cin, current_answer);

            if (Util::StrUtil::is_number(current_answer)) {
                size_t chosen_index = (size_t)stoi(current_answer);
                if (chosen_index < options.size()) {
                    current_answer = options[chosen_index];
                    current_answer_is_valid = true;
                }
            } else {
                current_answer_is_valid = Util::StrUtil::vector_contains_string(options, current_answer);
            }

            if (!current_answer_is_valid) {
                cout << "Invalid input" << endl;
            }
        }

        cout << endl;

        return current_answer;
    }

    string CommandLineInterface::ask_for_options(OptionsQuestion options)
    {
        return this->ask_for_options(options.question, options.options);
    }

    int CommandLineInterface::ask_for_number(string question, int min, int max)
    {
        int current_answer = -1;
        string current_answer_string = "";
        bool current_answer_is_valid = false;

        cout << question << endl;

        while (!current_answer_is_valid) {
            cout << "> ";
            std::getline(cin, current_answer_string);

            try {
                current_answer = stoi(current_answer_string);
                current_answer_is_valid = current_answer >= min && current_answer <= max;
            } catch (std::exception e) {

            }

            if (!current_answer_is_valid) {
                cout << "Invalid input" << endl;
            }
        }

        return current_answer;
    }

    int CommandLineInterface::ask_for_number(NumberQuestion number_question)
    {
        return this->ask_for_number(number_question.question, number_question.min, number_question.max);
    }

    bool CommandLineInterface::ask_for_yes_no(string question)
    {
        string current_answer = "";
        bool answer = false;
        bool current_answer_is_valid = false;

        cout << question << endl;
        cout << "[yes/no]" << endl;

        while (!current_answer_is_valid) {
            cout << "> ";
            std::getline(cin, current_answer);

            current_answer_is_valid = this->is_valid_yes_no(current_answer);

            if (current_answer_is_valid) {
                // We can't just set answer to either of these if clausules since we have to explicitly check for BOTH
                if (std::find(this->valid_yes.begin(), this->valid_yes.end(), current_answer) != this->valid_yes.end()) {
                    answer = true;
                }
                else if (std::find(this->valid_no.begin(), this->valid_no.end(), current_answer) != this->valid_no.end()) {
                    answer = false;
                }
            } else {
                cout << "Invalid input" << endl;
            }
        }

        return answer;
    }

    bool CommandLineInterface::is_valid_yes_no(string answer)
    {
        auto c = this->valid_yes_no_answers;
        return std::find(c.begin(), c.end(), answer) != c.end();
    }
}
