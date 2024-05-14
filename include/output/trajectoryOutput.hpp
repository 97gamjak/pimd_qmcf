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

#ifndef _TRAJECTORY_OUTPUT_HPP_

#define _TRAJECTORY_OUTPUT_HPP_

#include "output.hpp"   // for Output

namespace simulationBox
{
    class SimulationBox;   // forward declaration
}

namespace output
{
    /**
     * @class TrajectoryOutput inherits from Output
     *
     * @brief Output for xyz, vel, force, charges files
     *
     */
    class TrajectoryOutput : public Output
    {
      public:
        using Output::Output;

        void writeHeader(const simulationBox::SimulationBox &);
        void writeXyz(simulationBox::SimulationBox &);
        void writeVelocities(simulationBox::SimulationBox &);
        void writeForces(simulationBox::SimulationBox &);
        void writeCharges(simulationBox::SimulationBox &);
    };

}   // namespace output

#endif   // _TRAJECTORY_OUTPUT_HPP_