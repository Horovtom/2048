cmake_minimum_required(VERSION 3.9)

project(2048)

set(SOURCES
    src/main.cpp    
    src/Game.cpp
    src/Grid.cpp
)

add_executable(2048 ${SOURCES})

# Set the directories that should be included in the build command for this target
# when running g++ these will be included as -I/directory/path
target_include_directories(2048
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)