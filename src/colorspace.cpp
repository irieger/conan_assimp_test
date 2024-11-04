// This file is part of the AliceVision project.
// Copyright (c) 2022 AliceVision contributors.
// This Source Code Form is subject to the terms of the Mozilla Public License,
// v. 2.0. If a copy of the MPL was not distributed with this file,
// You can obtain one at https://mozilla.org/MPL/2.0/.

#include "colorspace.hpp"

#include <OpenImageIO/color.h>

#include <boost/algorithm/string.hpp>

#include <filesystem>
#include <vector>

namespace aliceVision {
namespace image {

namespace {
oiio::ColorConfig colorConfigOCIO(getDefaultColorConfigFilePath());
}

namespace fs = std::filesystem;

oiio::ColorConfig& getGlobalColorConfigOCIO() { return colorConfigOCIO; }

std::string getColorConfigFilePathFromSourceCode()
{
    const fs::path moduleFolder = fs::path(__FILE__).parent_path();
    return (moduleFolder / "share/aliceVision/config.ocio").string();
}

std::string getDefaultColorConfigFilePath()
{
    std::string configOCIOFilePath = "";

    char const* ALICEVISION_OCIO = std::getenv("ALICEVISION_OCIO");
    if (ALICEVISION_OCIO != NULL)
    {
        configOCIOFilePath = std::string(ALICEVISION_OCIO);
        // Check if a sRGB linear color space named "scene-linear Rec.709-sRGB" is present and set as scene_linear role
        oiio::ColorConfig colorConfig(configOCIOFilePath);
        const std::string linearColorSpace = colorConfig.getColorSpaceNameByRole("scene_linear");
        if (linearColorSpace == "scene-linear Rec.709-sRGB")
        {
            return configOCIOFilePath;
        }
    }
    return configOCIOFilePath;
}

}  // namespace image
}  // namespace aliceVision
