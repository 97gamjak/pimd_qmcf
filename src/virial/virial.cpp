#include "virial.hpp"

#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

void Virial::calculateVirial(SimulationBox &simulationBox, PhysicalData &physicalData)
{
    _virial = {0.0, 0.0, 0.0};

    for (auto &molecule : simulationBox._molecules)
    {
        const size_t numberOfAtoms = molecule.getNumberOfAtoms();

        for (size_t i = 0; i < numberOfAtoms; ++i)
        {
            const auto forcexyz = molecule.getAtomForces(i);
            const auto shiftForcexyz = molecule.getAtomShiftForces(i);
            const auto xyz = molecule.getAtomPositions(i);

            _virial += forcexyz * xyz + shiftForcexyz;

            molecule.setAtomShiftForces(i, {0.0, 0.0, 0.0});
        }
    }

    physicalData.setVirial(_virial);
}

void VirialMolecular::calculateVirial(SimulationBox &simulationBox, PhysicalData &physicalData)
{
    Virial::calculateVirial(simulationBox, physicalData);

    intraMolecularVirialCorrection(simulationBox);

    physicalData.setVirial(_virial);
}

void VirialMolecular::intraMolecularVirialCorrection(const SimulationBox &simulationBox)
{
    const auto box = simulationBox._box.getBoxDimensions();

    for (const auto &molecule : simulationBox._molecules)
    {
        const auto centerOfMass = molecule.getCenterOfMass();
        const size_t numberOfAtoms = molecule.getNumberOfAtoms();

        for (size_t i = 0; i < numberOfAtoms; ++i)
        {
            const auto forcexyz = molecule.getAtomForces(i);
            const auto xyz = molecule.getAtomPositions(i);

            auto dxyz = xyz - centerOfMass;

            dxyz -= box * round(dxyz / box);

            _virial -= forcexyz * dxyz;
        }
    }
}