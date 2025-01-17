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

#ifndef _RING_POLYMER_SETUP_HPP_

#define _RING_POLYMER_SETUP_HPP_

#include "typeAliases.hpp"

namespace setup
{
    void setupRingPolymer(pq::Engine &);

    /**
     * @class RingPolymerSetup
     *
     * @details class to setup a ring polymer simulation
     *
     */
    class RingPolymerSetup
    {
       private:
        pq::RingPolymerEngine &_engine;

       public:
        explicit RingPolymerSetup(pq::RingPolymerEngine &engine);

        void setup();
        void setupPhysicalData();
        void setupSimulationBox();
        void initializeBeads();
        void initializeVelocitiesOfBeads();
    };

}   // namespace setup

#endif   // _RING_POLYMER_SETUP_HPP_