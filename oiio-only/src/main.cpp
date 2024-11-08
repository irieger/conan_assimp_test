#include <iostream>
#include <filesystem>

#include <OpenImageIO/color.h>


int main(int argc, char* argv[])
{
    const auto fpath = std::filesystem::path(__FILE__).parent_path().parent_path().parent_path() / "config.ocio";
    std::cout << "Trying to load path: " << fpath << std::endl;
    OIIO::ColorConfig testConfig(fpath.string());

    std::cout << "Number of color spaces: " << testConfig.getNumColorSpaces() << std::endl;

    return 0;
}