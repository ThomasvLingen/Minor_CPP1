//
// Created by mafn on 10/21/16.
//

#include "CommandLineInterface.hpp"
#include "util/StrUtil.hpp"

namespace CLI {

    string CommandLineInterface::ask_for_options(string question, vector<string> options)
    {
        cout << question << endl << endl;

        this->_print_options(options);

        return Util::StrUtil::to_lower(this->_get_option(options));
    }

    size_t CommandLineInterface::ask_for_options_by_index(string question, vector<string> options)
    {
        cout << question << endl << endl;

        this->_print_options(options);

        return this->_get_option_index(options);
    }

    size_t CommandLineInterface::ask_for_options_by_index(OptionsQuestion options)
    {
        return this->ask_for_options_by_index(options.question, options.options);
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

    void CommandLineInterface::_print_options(vector<string> options)
    {
        for (uint i = 0; i < options.size(); i++) {
            cout << i << " " << options[i] << endl;
        }
    }

    string CommandLineInterface::_get_option(vector<string> options)
    {
        size_t chosen_index = this->_get_option_index(options);

        return options[chosen_index];
    }

    size_t CommandLineInterface::_get_option_index(vector<string> options)
    {
        string current_answer = "";
        size_t final_answer = 0;
        bool current_answer_is_valid = false;

        while(!current_answer_is_valid) {
            cout << "> ";
            std::getline(cin, current_answer);

            if (Util::StrUtil::is_number(current_answer)) {
                size_t chosen_index = (size_t)stoi(current_answer);
                if (chosen_index < options.size()) {
                    final_answer = chosen_index;
                    current_answer_is_valid = true;
                }
            } else {
                if (Util::StrUtil::vector_contains_string(options, current_answer)) {
                    final_answer = Util::StrUtil::get_index_of_string(options, current_answer);
                    current_answer_is_valid = true;
                }
            }

            if (!current_answer_is_valid) {
                cout << "Invalid input" << endl;
            }
        }

        cout << endl;

        return final_answer;
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

            if (Util::StrUtil::is_number(current_answer_string)) {
                // This try catch is for integer overflows
                try {
                    current_answer = stoi(current_answer_string);
                    current_answer_is_valid = current_answer >= min && current_answer <= max;
                } catch (std::exception e) {
                }
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

            current_answer_is_valid = this->_is_valid_yes_no(current_answer);

            if (current_answer_is_valid) {
                // We can't just set answer to either of these if clausules since we have to explicitly check for BOTH
                if (this->_is_valid_yes(current_answer)) {
                    answer = true;
                }
                else if (this->_is_valid_no(current_answer)) {
                    answer = false;
                }
            } else {
                cout << "Invalid input" << endl;
            }
        }

        return answer;
    }

    bool CommandLineInterface::_is_valid_yes_no(string answer)
    {
        return this->_is_valid_no(answer) || this->_is_valid_yes(answer);
    }

    bool CommandLineInterface::_is_valid_yes(string answer)
    {
        return Util::StrUtil::vector_contains_string(this->_valid_yes, answer);
    }

    bool CommandLineInterface::_is_valid_no(string answer)
    {
        return Util::StrUtil::vector_contains_string(this->_valid_no, answer);
    }
}
