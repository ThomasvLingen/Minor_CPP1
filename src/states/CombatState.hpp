//
// Created by jazula on 10/29/16.
//

#ifndef MINOR_CPP1_COMBATSTATE_HPP
#define MINOR_CPP1_COMBATSTATE_HPP

#include <player/Player.hpp>
#include "State.hpp"
#include "CommandLineInterface.hpp"

namespace States
{
    using Items::Item;
    using std::vector;
    using std::string;
    using std::cout;
    using std::endl;
    using std::map;

    class CombatState : public State {

    public:
        CombatState(Game::Game &game);
        virtual ~CombatState();

        virtual void run() override;

    private:
        bool _state_active = true;

        CLI::OptionsQuestion _menu = {
            .question = "What will you do?",
            .options  = {"Attack", "Flee", "Search For Item", "Rest", "Use Item", "Open Map"}
        };

        map<Dungeon::Direction, string> _direction_to_string = {
            {Dungeon::Direction::north, "North"},
            {Dungeon::Direction::east, "East"},
            {Dungeon::Direction::south, "South"},
            {Dungeon::Direction::west, "West"},
        };

        void _attack_handler();
        void _flee_handler();
        void _search_handler();
        void _rest_handler();
        void _item_use_handler();
        void _map_handler();

        void _stair_handler();

        Player::Player* _get_player();

    };

}

#endif //MINOR_CPP1_COMBATSTATE_HPP
