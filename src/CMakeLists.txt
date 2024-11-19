find_package(Curses REQUIRED)

add_executable(game_of_snake main.cpp)

include_directories(${CURSES_INCLUDE_DIR})

target_link_libraries(game_of_snake ${CURSES_LIBRARIES})

add_library(snake snake.cpp)
add_library(game_map gameMap.cpp)