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

#include "mmEvaluator.hpp"

#include "celllist.hpp"
#include "constraints.hpp"
#include "forceFieldClass.hpp"
#include "intraNonBonded.hpp"
#include "potential.hpp"
#include "simulationBox.hpp"
#include "virial.hpp"

using namespace opt;

/**
 * @brief update forces
 *
 */
void MMEvaluator::updateForces()
{
    // _constraints->applyShake(_simulationBox);

    _cellList->updateCellList(*_simulationBox);

#ifdef WITH_KOKKOS
    throw std::runtime_error("Kokkos not implemented in Optimizer");
    _kokkosPotential.calculateForces(
        _simulationBox,
        _kokkosSimulationBox,
        _physicalData,
        _kokkosLennardJones,
        _kokkosCoulombWolf
    );
#else
    _potential->calculateForces(*_simulationBox, *_physicalData, *_cellList);
#endif

    _intraNonBonded->calculate(*_simulationBox, *_physicalData);

    // _virial->calculateVirial(_simulationBox, _physicalData);

    _forceField->calculateBondedInteractions(*_simulationBox, *_physicalData);

    // _constraints->applyDistanceConstraints(
    //     _simulationBox,
    //     _physicalData,
    //     calculateTotalSimulationTime()
    // );

    // _constraints.calculateConstraintBondRefs(_simulationBox);

    // _virial->intraMolecularVirialCorrection(_simulationBox, _physicalData);

    // _constraints.applyRattle(_simulationBox);
}