//
// Created by mafn on 10/21/16.
//

#include "CreateCharacterState.hpp"
#include "MenuState.hpp"
#include <Game.hpp>
#include <fmt/format.h>

namespace States {

    CreateCharacterState::CreateCharacterState(Game::Game &game)
    : State(game)
    {

    }

    void CreateCharacterState::run()
    {
        bool player_made_character = false;
        Player* created_player = nullptr;

        cout << "Welcome to the hero creation menu" << endl;

        while(!player_made_character) {
            created_player = this->create_player();
            created_player->print();

            player_made_character = this->game.cli.ask_for_yes_no("Are you satisfied with this character?");

            // If the player is not satisfied, we discard the created player
            if (!player_made_character) {
                delete created_player;
            }
        }

        this->game.players.add_player(created_player);

        this->game.change_state(new MenuState(this->game));
    }

    Player *CreateCharacterState::create_player()
    {
        // Make base hero
        int points_left_for_allocation = 60;
        string name = this->game.cli.ask_for_string("Please enter a name for your hero");

        Player* hero = new Player(name);
        hero->reset_stats_for_creation();

        cout << fmt::format("We're now going to allocate stats, you start with {} points to allocate", points_left_for_allocation) << endl;
        cout << "1 point in Health costs 2 points" << endl;
        cout << "1 point in attack costs 1 point" << endl;
        cout << "1 point in defense costs 1 point" << endl;

        // Allocate health
        int min = 0;
        int max = points_left_for_allocation / 2;
        string question = fmt::format("How many hitpoints do you want on top of the base hp ({})? [{}-{}]", hero->health.max_health, min, max);
        int selected_health_points = this->game.cli.ask_for_number(question, min, max);
        hero->set_max_health(hero->health.max_health + selected_health_points);
        points_left_for_allocation -= selected_health_points * 2;

        // Allocate attack
        min = 0;
        max = points_left_for_allocation;
        question = fmt::format("How much attack do you want on top of the base atk ({})? [{}-{}]", hero->attack, min, max);
        int selected_attack_points = this->game.cli.ask_for_number(question, min, max);
        hero->attack += selected_attack_points;
        points_left_for_allocation -= selected_attack_points;

        // Allocate defence
        min = 0;
        max = points_left_for_allocation;
        question = fmt::format("How much defence do you want on top of the base def ({})? [{}-{}]", hero->defence, min, max);
        int selected_defence_points = this->game.cli.ask_for_number(question, min, max);
        hero->defence += selected_defence_points;
        points_left_for_allocation -= selected_defence_points;

        return hero;
    }

    CreateCharacterState::~CreateCharacterState()
    {

    }
}