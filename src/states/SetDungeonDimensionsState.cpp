//
// Created by mafn on 10/28/16.
//

#include <Game.hpp>
#include "SetDungeonDimensionsState.hpp"
#include "MenuState.hpp"


namespace States {

    SetDungeonDimensionsState::SetDungeonDimensionsState(Game::Game &game)
    : State(game)
    {

    }

    SetDungeonDimensionsState::~SetDungeonDimensionsState()
    {
    }

    void SetDungeonDimensionsState::run()
    {
        size_t width = (size_t)this->game.cli.ask_for_number(this->_width_question);
        size_t heigth = (size_t)this->game.cli.ask_for_number(this->_height_question);
        size_t floors = (size_t)this->game.cli.ask_for_number(this->_floors_question);

        this->game.set_dungeon_dimensions(Dungeon::DungeonDimensions {
            .width = width,
            .height = heigth,
            .floors = floors
        });

        this->game.change_state(new MenuState(this->game));
    }


}