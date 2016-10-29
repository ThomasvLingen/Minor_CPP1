//
// Created by mafn on 10/21/16.
//

#include "CreateCharacterState.hpp"
#include "MenuState.hpp"
#include "CharacterMenu.hpp"
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
        Player::Player* created_character = nullptr;

        cout << "Welcome to the hero creation menu" << endl;

        while(!player_made_character) {
            created_character = this->create_character();
            created_character->print();

            player_made_character = this->game.cli.ask_for_yes_no("Are you satisfied with this character?");

            // If the player is not satisfied, we discard the created player
            if (!player_made_character) {
                delete created_character;
            }
        }

        this->game.players.add_player(created_character);

        this->game.change_state(new CharacterMenu(this->game));
    }

    Player::Player *CreateCharacterState::create_character()
    {
        // Make base hero
        int points_left_for_allocation = 60;
        string name = this->game.cli.ask_for_string("Please enter a name for your hero");

        Player::Player* hero = new Player::Player(name);
        hero->reset_stats_for_creation();
        Stats& hero_stats = hero->get_stats();

        cout << fmt::format("We're now going to allocate stats, you start with {} points to allocate", points_left_for_allocation) << endl;
        cout << "1 point in Health costs 2 points" << endl;
        cout << "1 point in attack costs 1 point" << endl;
        cout << "1 point in defense costs 1 point" << endl;

        // Allocate health
        int hp_allocated = this->allocate_stat(points_left_for_allocation, 0, points_left_for_allocation / 2, hero_stats.health.max_health, 2, "health");
        hero_stats.set_max_health(hero_stats.health.max_health + hp_allocated);

        // Allocate attack
        int atk_allocated = this->allocate_stat(points_left_for_allocation, 0, points_left_for_allocation, hero_stats.hit_chance, 1, "attack");
        hero_stats.hit_chance += atk_allocated;

        // Allocate defence
        int def_allocated = this->allocate_stat(points_left_for_allocation, 0, points_left_for_allocation, hero_stats.defence, 1, "defence");
        hero_stats.defence += def_allocated;

        return hero;
    }

    CreateCharacterState::~CreateCharacterState()
    {

    }

    int CreateCharacterState::allocate_stat(int &points_left, int min, int max, int base_stat, int points_per_stat,
                                            string stat_name)
    {
        string question = fmt::format("How much {0} do you want on top of the base {0} ({1}) [{2}-{3}]", stat_name, base_stat, min, max);

        int selected_points = this->game.cli.ask_for_number(question, min, max);
        points_left -= selected_points * points_per_stat;

        return selected_points;
    }
}