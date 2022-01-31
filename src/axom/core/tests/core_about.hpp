// Copyright (c) 2017-2022, Lawrence Livermore National Security, LLC and
// other Axom Project Developers. See the top-level LICENSE file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)

#include "gtest/gtest.h"

#include "axom/config.hpp"
#include "axom/core/utilities/About.hpp"

// C/C++ includes
#include <sstream>  // for std::ostringstream

TEST(core_about, print_about) { axom::about(); }

//-----------------------------------------------------------------------------
TEST(core_about, get_version)
{
  std::ostringstream EXPECTED_VERSION_STRING;
  EXPECTED_VERSION_STRING << AXOM_VERSION_FULL;
#ifdef AXOM_VERSION_EXTRA
  EXPECTED_VERSION_STRING << "-" << AXOM_VERSION_EXTRA;
#endif

  std::string axom_version = axom::getVersion();
  EXPECT_EQ(EXPECTED_VERSION_STRING.str(), axom_version);
}