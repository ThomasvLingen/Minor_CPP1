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

        if (result == "search for item") {
            this->_search_handler();
        }
        else if (result == "flee") {
            this->_flee_handler();
        }
        else if (result == "open map") {
            this->_map_handler();
        }
    }
}

void States::CombatState::_search_handler()
{
    Player::Player* player = this->_get_player();
    Item* item = player->current_room->get_item();

    if(item != nullptr){
        cout << "You found a " << item->get_name() << endl;
        cout << "    " << item->get_description() << endl;
        cout << "Added to items" << endl;
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

    size_t response_index = this->game.cli.ask_for_options_by_index(question);
    cout << "You fled " << options[response_index] << endl;
    player->move_direction(possible_directions[response_index]);
    player->current_room->discover(this->game._enemy_factory);

    if(player->current_room->room_type == Dungeon::RoomType::stair_down
        || player->current_room->room_type == Dungeon::RoomType::stair_up){

        this->_stair_handler();
    }
}

void States::CombatState::_map_handler()
{
    this->_get_player()->current_room->container_floor.print_floor();
}

void States::CombatState::_stair_handler()
{
    Player::Player *player = this->_get_player();

    bool player_want_to_use_stairs = this->game.cli.ask_for_yes_no("Do you want to use the stair case?");

    if (player_want_to_use_stairs) {
        Dungeon::Room* next_floor_room = player->current_room->container_floor.get_floor(player->current_room)->start_room;

        player->current_room = next_floor_room;
        player->current_room->discover(this->game._enemy_factory);
    }
}
