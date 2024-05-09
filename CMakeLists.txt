cmake_minimum_required(VERSION 3.15)
project(game CXX)

find_package(assimp REQUIRED)

add_executable(game src/main.cpp)
target_link_libraries(game assimp::assimp)


install(TARGETS game DESTINATION "."
        RUNTIME DESTINATION bin
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        )
