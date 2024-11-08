#include <iostream>
#include <filesystem>

#include <OpenImageIO/color.h>

#include <assimp/Importer.hpp>


int main(int argc, char* argv[])
{
    const auto fpath = std::filesystem::path(__FILE__).parent_path().parent_path().parent_path() / "config.ocio";
    std::cout << "Trying to load path: " << fpath << std::endl;
    OIIO::ColorConfig testConfig(fpath.string());

    std::cout << "Number of color spaces: " << testConfig.getNumColorSpaces() << std::endl;
    std::cout << "Lin space: " << testConfig.getColorSpaceNameByRole("scene_linear") << std::endl;

    Assimp::Importer importer;

    if (argc >= 2)
    {
        std::cout << "Trying to load path: " << argv[1] << std::endl;
        OIIO::ColorConfig testConfig2(argv[1]);
        std::cout << "Number of color spaces: " << testConfig2.getNumColorSpaces() << std::endl;
        std::cout << "Lin space: " << testConfig2.getColorSpaceNameByRole("scene_linear") << std::endl;
    }

    if (argc >= 3)
    {
        const aiScene* scene = scene = importer.ReadFile(argv[2], 0);
    }

    return 0;
}
