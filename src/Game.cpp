//
// Created by mafn on 10/21/16.
//

#include <util/StrUtil.hpp>
#include <states/MenuState.hpp>
#include <dungeon/generator/DungeonGenerator.hpp>
#include "Game.hpp"

namespace Game {

    Game::Game()
    : dungeon(nullptr)
    , _item_factory()
    , _enemy_factory("./res/monsters.txt")
    , _current_state(new States::MenuState(*this))
    , _old_state(nullptr)
    , dimensions(DungeonDimensions {
        .width = 5,
        .height = 5,
        .floors = 5
    })
    {
        this->_item_factory.register_useables();
        this->_item_factory.register_weapons("./res/weapons.txt");
    }

    Game::~Game()
    {
        delete dungeon;
        delete this->_current_state;
    }

    void Game::run()
    {
        while(this->_running) {
            this->_current_state->run();
            this->delete_old_state();
        }
    }

    void Game::change_state(States::State *state)
    {
        this->_old_state = this->_current_state;

        this->_current_state = state;
    }

    void Game::delete_old_state()
    {
        if (this->_old_state != nullptr) {
            delete this->_old_state;
        }

        this->_old_state = nullptr;
    }

    void Game::quit()
    {
        this->_running = false;
    }

    void Game::set_dungeon_dimensions(DungeonDimensions new_dimensions)
    {
        this->dimensions = new_dimensions;
    }

    void Game::generate_dungeon()
    {
        Dungeon::Generator::DungeonGenerator generator(&this->_enemy_factory, &this->_item_factory);

        this->dungeon = generator.create_dungeon(this->dimensions);
    }
}