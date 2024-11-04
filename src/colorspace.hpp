// This file is part of the AliceVision project.
// Copyright (c) 2022 AliceVision contributors.
// This Source Code Form is subject to the terms of the Mozilla Public License,
// v. 2.0. If a copy of the MPL was not distributed with this file,
// You can obtain one at https://mozilla.org/MPL/2.0/.

#pragma once

#include <string>
#include <istream>
#include <ostream>

#include <OpenImageIO/color.h>

namespace oiio = OIIO;

namespace aliceVision {
namespace image {

std::string getDefaultColorConfigFilePath();
void initColorConfigOCIO(const std::string& colorConfigFilePath);
oiio::ColorConfig& getGlobalColorConfigOCIO();

}  // namespace image
}  // namespace aliceVision
