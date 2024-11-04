cmake_minimum_required(VERSION 3.15)
project(game CXX)

find_package(assimp REQUIRED)
find_package(OpenImageIO REQUIRED)

add_executable(game src/main.cpp src/colorspace.hpp src/colorspace.cpp)
target_link_libraries(game assimp::assimp
OpenImageIO::OpenImageIO
OpenImageIO::OpenImageIO_Util)


install(TARGETS game DESTINATION "."
        RUNTIME DESTINATION bin
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        )
