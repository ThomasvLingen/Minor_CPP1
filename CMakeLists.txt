cmake_minimum_required(VERSION 3.5)
project(Minor_CPP1)
include_directories(src)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    src/main.cpp
        src/states/State.hpp src/dungeon/Dungeon.cpp src/dungeon/Dungeon.hpp src/dungeon/Floor.cpp src/dungeon/Floor.hpp src/dungeon/Room.cpp src/dungeon/Room.hpp src/monsters/Enemy.cpp src/monsters/Enemy.hpp src/items/Item.cpp src/items/Item.hpp src/dungeon/generator/DungeonGenerator.cpp src/dungeon/generator/DungeonGenerator.hpp src/dungeon/generator/FloorGenerator.cpp src/dungeon/generator/FloorGenerator.hpp src/dungeon/generator/RoomGenerator.cpp src/dungeon/generator/RoomGenerator.hpp)

add_executable(Minor_CPP1 ${SOURCE_FILES})
