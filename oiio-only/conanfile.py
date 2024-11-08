from conan import ConanFile
from conan.tools.cmake import CMakeToolchain, CMake, cmake_layout, CMakeDeps
import os

class AliceVisionRecipe(ConanFile):
    name = "conan_assimp_test"
    version = "0.0.1"
    package_type = "application"
    settings = "os", "compiler", "build_type", "arch"

    exports_sources = "CMakeLists.txt", "src/**", "docs/**", "**.md"

    options = {
        "shared": [True, False],
        "fPIC": [True, False],
    }
    default_options = {
        "shared": False,
        "fPIC": True,
    }

    @property
    def _min_cppstd(self):
        return 17

    def config_options(self):
        if self.settings.os == "Windows":
            del self.options.fPIC

    def layout(self):
        cmake_layout(self)

    def requirements(self):
        #self.requires("assimp/5.4.3")
        self.requires("openimageio/2.5.16.0")

    def generate(self):
        tc = CMakeToolchain(self)
        tc.generate()

        deps = CMakeDeps(self)
        #deps.set_property("minizip", "cmake_target_name", "MINIZIP::minizip")
        #deps.set_property("minizip", "cmake_file_name", "MINIZIP")
        deps.generate()
        
    def build(self):
        cmake = CMake(self)
        #cmake.configure(cli_args=["--graphviz=graph.dot"])
        # dot -Tsvg -o graph.svg build/Release/graph.dot
        cmake.build(cli_args=["--verbose"], build_tool_args=["-j 5"])

