/*****************************************************************************
<GPL_HEADER>

    PQ
    Copyright (C) 2023-now  Jakob Gamper

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

<GPL_HEADER>
******************************************************************************/

#include "testQMSetupAse.hpp"   // for TestQMSetupAse

#include <gtest/gtest.h>   // for Test, TestInfo (ptr only), InitGoogleTest, RUN_ALL_TESTS

#include <string>   // for allocator, basic_string

#include "exceptions.hpp"         // for InputFileException
#include "gtest/gtest.h"          // for Message, TestPartResult
#include "qmRunner.hpp"           // for QMRunner
#include "qmSettings.hpp"         // for QMMethod, QMSettings
#include "qmSetup.hpp"            // for QMSetup, setupQM
#include "qmmdEngine.hpp"         // for QMMDEngine
#include "throwWithMessage.hpp"   // for ASSERT_THROW_MSG

using setup::QMSetup;
using namespace settings;

TEST_F(TestQMSetupAse, setupAseDftbplus3OB)
{
    engine::QMMDEngine engine;
    QMSetup            setupQM = QMSetup(engine);

    engine.getEngineOutput().getLogOutput().setFilename("default.log");
    QMSettings::setQMMethod(QMMethod::ASEDFTBPLUS);
    QMSettings::setSlakosType("3ob");
    setupQM.setupWriteInfo();

    std::ifstream file("default.log");
    std::string   line;
    getline(file, line);
    EXPECT_EQ(line, "         QM runner: ASEDFTBPLUS");
    getline(file, line);
    EXPECT_EQ(line, "");
    getline(file, line);
    EXPECT_EQ(line, "         DFTB approach:       3ob");
    getline(file, line);
    // clang-format off
    std::string skPath {__SLAKOS_DIR__ + string(SlakosType::THREEOB) + "/skfiles/"};
    EXPECT_EQ(line, "         sk file path:        " + skPath);
    // clang-format on
    getline(file, line);
    EXPECT_EQ(line, "         3rd order is turned: on");
}