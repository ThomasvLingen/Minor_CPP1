//
// Created by jazula on 10/29/16.
//

#include <Game.hpp>
#include <vector>
#include "CombatState.hpp"
#include <dungeon/Floor.hpp>

States::CombatState::CombatState(Game::Game &game) : State(game)
{}

States::CombatState::~CombatState()
{

}

void States::CombatState::run()
{
    while (this->_state_active) {
        string result = this->game.cli.ask_for_options(this->_menu);

        if(result == "search for item"){
            this->_search_handler();
        }
    }
}

void States::CombatState::_search_handler()
{
    Player::Player* player = this->_get_player();
    Item* item = player->current_room->get_item();

    if(item != nullptr){
        cout << "You found a " << item->get_name() << endl;
        cout << "\t" << item->get_description() << endl;
        cout << "Added to items";
        player->add_item(item);
    } else {
        cout << "Nothing of interest was found" << endl;
    }
}

Player::Player *States::CombatState::_get_player()
{
    return game.players.get_selected_player();
}

void States::CombatState::_flee_handler()
{
    Player::Player *player = this->_get_player();
    vector<Dungeon::Direction> possible_directions = player->current_room->container_floor.get_available_directions(
        player->current_room);

    vector<string> options;
    for (auto dir : possible_directions) {
        options.push_back(this->_direction_to_string[dir]);
    }

    CLI::OptionsQuestion question = {
        .question = "Which direction will you flee to?",
        .options = options
    };

    string response = this->game.cli.ask_for_options(question);

    // TODO: We currently have the direction to go to in a string, we want this in a direction instead so that we can move our player.
    // Then move player
}