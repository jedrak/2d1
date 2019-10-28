cmake_minimum_required(VERSION 3.6)
project(2d_games_ex1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 ")
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ ")

include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/lib)

set(SOURCE_FILES src/main.cpp src/GameObject.cpp src/Player.cpp include/Player.h)
add_executable(2d_games_ex1 ${SOURCE_FILES})
target_link_libraries(2d_games_ex1 mingw32 SDL2_image SDL2_gfx SDL2main SDL2 )
