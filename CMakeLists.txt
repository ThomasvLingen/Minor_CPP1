cmake_minimum_required(VERSION 3.3)
project(Minor_CPP1)
include_directories(src)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    src/main.cpp
    src/Game.hpp src/Game.cpp
    src/states/State.hpp src/states/State.cpp
    src/states/CommandLineInterface.cpp src/states/CommandLineInterface.hpp
    src/states/CreateCharacterState.cpp src/states/CreateCharacterState.hpp
    src/states/MenuState.cpp src/states/MenuState.hpp
    src/dungeon/Dungeon.cpp src/dungeon/Dungeon.hpp
    src/dungeon/Floor.cpp src/dungeon/Floor.hpp
    src/dungeon/Room.cpp src/dungeon/Room.hpp
    src/dungeon/generator/DungeonGenerator.cpp src/dungeon/generator/DungeonGenerator.hpp
    src/dungeon/generator/FloorGenerator.cpp src/dungeon/generator/FloorGenerator.hpp
    src/dungeon/generator/RoomGenerator.cpp src/dungeon/generator/RoomGenerator.hpp
    src/items/Item.cpp src/items/Item.hpp
    src/monsters/Enemy.cpp src/monsters/Enemy.hpp
    src/monsters/EnemyFactory.cpp src/monsters/EnemyFactory.hpp
    src/monsters/MonsterFileParser.cpp src/monsters/MonsterFileParser.hpp
    src/util/StrUtil.cpp src/util/StrUtil.hpp
    src/util/RandomUtil.cpp src/util/RandomUtil.hpp
    src/player/Player.cpp src/player/Player.hpp
)

add_executable(Minor_CPP1 ${SOURCE_FILES})

add_custom_command(TARGET Minor_CPP1 PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/res $<TARGET_FILE_DIR:Minor_CPP1>/res)