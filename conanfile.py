from conan import ConanFile
from conan.tools.cmake import CMakeToolchain, CMake, cmake_layout, CMakeDeps


class conan_assimp_testRecipe(ConanFile):
    name = "conan_assimp_test"
    version = "0.0.1"
    package_type = "application"
    settings = "os", "compiler", "build_type", "arch"

    exports_sources = "CMakeLists.txt", "src/*"

    @property
    def _min_cppstd(self):
        return 17


    def layout(self):
        cmake_layout(self)

    def requirements(self):
        self.requires("assimp/5.3.1")
        self.requires("openimageio/2.5.10.1")
        self.requires("boost/1.84.0")
        self.requires("eigen/3.4.0")
        self.requires("openexr/3.2.3", override=True)
        self.requires("ceres-solver/2.1.0")

    def build_requirements(self):
        self.tool_requires("ccache/4.9.1")

    def generate(self):
        deps = CMakeDeps(self)
        deps.generate()
        tc = CMakeToolchain(self)
        tc.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        cmake = CMake(self)
        cmake.install()
