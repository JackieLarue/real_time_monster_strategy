cmake_minimum_required(VERSION 3.5)
project(pocket_move_proto C)
set(CMAKE_C_STANDARD 23)

# Adding Raylib
include(FetchContent)
FetchContent_Declare(flecs GIT_REPOSITORY https://github.com/SanderMertens/flecs.git GIT_TAG master)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) # don't build the supplied example games
FetchContent_Declare(raylib GIT_REPOSITORY https://github.com/raysan5/raylib.git GIT_TAG master)
FetchContent_Declare(ccd GIT_REPOSITORY https://github.com/danfis/libccd.git GIT_TAG master)
FetchContent_MakeAvailable(raylib flecs ccd)

# Adding our source files
file(GLOB_RECURSE PROJECT_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/src/*.c") # Define PROJECT_SOURCES as a list of all source files
set(PROJECT_INCLUDE "${CMAKE_CURRENT_LIST_DIR}/include/") # Define PROJECT_INCLUDE to be the path to the include directory of the project

# Declaring our executable
add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_INCLUDE})
target_link_libraries(${PROJECT_NAME} PRIVATE raylib PRIVATE flecs::flecs_static PRIVATE ccd)

# Setting Compiler Flags
set(CMAKE_C_FLAGS_DEBUG "-Wall -Werror -Wextra -g3")
set(CMAKE_C_FLAGS_RELEASE "-O3 -Wall -Werror -Wextra")