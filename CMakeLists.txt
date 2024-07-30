cmake_minimum_required(VERSION 3.28)
project(Snake___Ladder)

set(CMAKE_CXX_STANDARD 17)

add_executable(Snake___Ladder src/snakeAndLadderApplication.cpp src/utils/Snake.cpp
        ../Snake&Ladder/snake.h
        src/utils/Ladder.cpp
        include/Ladder.h
        src/utils/Player.cpp
        include/Player.h
        src/utils/Dice.cpp
        include/Dice.h
        src/utils/Board.cpp
        include/Board.h
        src/service/SnakeAndLadderService.cpp
        include/SnakeAndLadderService.h
        src/input/SnakeInput.cpp
        include/SnakeInput.h
        src/input/LadderInput.cpp
        include/LadderInput.h
        src/input/PlayerInput.cpp
        include/PlayerInput.h
)
