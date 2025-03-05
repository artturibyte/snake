find_package(Curses REQUIRED)
find_package(SFML COMPONENTS graphics REQUIRED)

add_executable(game_of_snake main.cpp)

include_directories(${CURSES_INCLUDE_DIR})

target_link_libraries(game_of_snake ${CURSES_LIBRARIES})
target_link_libraries(game_of_snake sfml-graphics)

add_library(game_of_snake snake.cpp)
add_library(game_of_snake OBJECT gameMap.cpp)