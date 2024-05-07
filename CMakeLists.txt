cmake_minimum_required(VERSION 3.15)
project(conan_assimp_test CXX)

find_package(assimp REQUIRED CONFIG)

add_executable(${PROJECT_NAME} src/conan_assimp_test.cpp src/main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE assimp::assimp)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_11)

install(TARGETS ${PROJECT_NAME} DESTINATION "."
        RUNTIME DESTINATION bin
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        )
