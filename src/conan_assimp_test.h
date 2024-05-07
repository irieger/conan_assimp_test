#pragma once

#include <vector>
#include <string>


#ifdef _WIN32
  #define CONAN_ASSIMP_TEST_EXPORT __declspec(dllexport)
#else
  #define CONAN_ASSIMP_TEST_EXPORT
#endif

CONAN_ASSIMP_TEST_EXPORT void conan_assimp_test();
CONAN_ASSIMP_TEST_EXPORT void conan_assimp_test_print_vector(const std::vector<std::string> &strings);
