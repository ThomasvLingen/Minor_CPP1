//
// Created by mafn on 10/28/16.
//

#ifndef MINOR_CPP1_CHARACTERMENU_HPP
#define MINOR_CPP1_CHARACTERMENU_HPP

#include "State.hpp"
#include "CommandLineInterface.hpp"


namespace States {
    class CharacterMenu : public State {
    public:
        CharacterMenu(Game::Game& game);
        virtual ~CharacterMenu();

        virtual void run() override;

    private:
        CLI::OptionsQuestion _menu = {
            .question = "This is the character menu, please select something from the menu",
            .options = {"Create", "List", "Select", "Remove", "Save", "Back"}
        };
        bool _state_active = true;

        // Handlers
        void _create_handler();
        void _list_handler();
        void _select_handler();
        void _remove_handler();
        void _save_handler();
        void _back_handler();
    };
}


#endif //MINOR_CPP1_CHARACTERMENU_HPP
