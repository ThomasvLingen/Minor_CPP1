//
// Created by jazula on 10/29/16.
//

#include <Game.hpp>
#include <vector>
#include "CombatState.hpp"
#include "MenuState.hpp"
#include <dungeon/Floor.hpp>

States::CombatState::CombatState(Game::Game &game) : State(game)
{}

States::CombatState::~CombatState()
{

}

void States::CombatState::run()
{
    bool next_turn = true;
    while (this->_state_active) {

        if(next_turn){
            _enemies_attack_turn();

            if (!this->_state_active) {
                break;
            }

            next_turn = false;
        }

        string result = this->game.cli.ask_for_options(this->_menu);

        if (result == "search for item") {
            this->_search_handler();
            next_turn = true;
        }
        else if (result == "look at items") {
            this->_look_at_items_handler();
        }
        else if (result == "check stats") {
            this->_check_stats_handler();
        }
        else if (result == "attack") {
            this->_attack_handler();
            next_turn = true;
        }
        else if (result == "flee") {
            this->_flee_handler();
            next_turn = true;
        }
        else if (result == "rest"){
            this->_rest_handler();
            next_turn = true;
        }
        else if (result == "use item") {
            this->_item_use_handler();
        }
        else if (result == "open map") {
            this->_map_handler();
        }

        this->_check_win();
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
    Dungeon::Location player_location = this->_get_player()->current_room->location;
    this->_get_player()->current_room->container_floor.print_floor(player_location);
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

void States::CombatState::_attack_handler()
{
    Player::Player *player = this->_get_player();

    if(player->current_room->monsters.size() == 0){
        cout << "Nothing to attack you fool!" << endl;
    } else {
        CLI::OptionsQuestion question = {
            .question = "Who to attack?",
            .options = player->current_room->get_monster_names()
        };

        int enemy_to_attack_index = (int)this->game.cli.ask_for_options_by_index(question);
        player->attack(player->current_room->monsters[enemy_to_attack_index]);

        player->current_room->print_monsters();
    }
}

void States::CombatState::_enemies_attack_turn()
{
    Player::Player *player = this->_get_player();

    for (auto enemy : player->current_room->monsters) {
        enemy->attack_player(player);
    }

    if (player->get_stats().health.current_health > 0) {
        player->print_hp();
        cout << endl;
    } else {
        this->_handle_death();
    }
}

void States::CombatState::_handle_death()
{
    Player::Player* player = this->_get_player();

    cout << "Seems like you've run out of luck..." << endl;
    cout << "RIP " << player->get_name() << endl;

    this->game.players.remove_player(player);
    this->game.players.save_players();

    cout << "Your character has been deleted and your save file has been overwritten. :^)" << endl;

    this->game.change_state(new MenuState(this->game));
    this->_state_active = false;
}

void States::CombatState::_rest_handler()
{
    Player::Player* player = this->_get_player();
    player->current_room->generate_monsters(this->game._enemy_factory);
    player->current_room->print_monsters();

    player->rest();
}

void States::CombatState::_item_use_handler()
{
    Player::Player* player = this->_get_player();

    if (player->items.size() > 0){
        size_t chosen_item_index = this->game.cli.ask_for_options_by_index(CLI::OptionsQuestion {
            .question = "What item do you want to use?",
            .options = player->get_item_names()
        });

        player->use_item(chosen_item_index);
    } else {
        cout << "You don't have any items" << endl;
    }
}

void States::CombatState::_look_at_items_handler()
{
    Player::Player* player = this->_get_player();
    player->print_items();
}

void States::CombatState::_check_win(){
    Player::Player* player = this->_get_player();

    if(player->current_room->room_type == Dungeon::RoomType::boss && player->current_room->monsters.size() == 0){
        this->_state_active = false;
        this->game.change_state(new MenuState(this->game));

        cout << endl;
        cout << "Good werk you won, young padawan" << endl;
    }
}

void States::CombatState::_check_stats_handler()
{
    this->_get_player()->print();
}
