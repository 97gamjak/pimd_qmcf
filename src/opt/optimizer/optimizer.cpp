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

#include "optimizer.hpp"

#include <memory>   // for std::shared_ptr

using namespace opt;

/**
 * @brief Construct a new Optimizer object
 *
 * @param nEpochs
 * @param initialLearningRate
 */
Optimizer::Optimizer(const size_t nEpochs) : _nEpochs(nEpochs) {}

/**
 * @brief set simulation box shared pointer
 *
 * @param simulationBox
 */
void Optimizer::setSimulationBox(
    const std::shared_ptr<simulationBox::SimulationBox> simulationBox
)
{
    _simulationBox = simulationBox;
}