#include "physicalData.hpp"
#include "constants.hpp"

#include <vector>
#include <cmath>

using namespace std;

void PhysicalData::calculateKineticEnergyAndMomentum(const SimulationBox &simulationBox)
{
    auto momentum = Vec3D();

    _momentumVector = Vec3D();
    _kineticEnergyAtomicVector = Vec3D();
    _kineticEnergyMolecularVector = Vec3D();

    for (const auto &molecule : simulationBox._molecules)
    {
        const size_t numberOfAtoms = molecule.getNumberOfAtoms();
        auto momentumSquared = Vec3D();

        for (size_t i = 0; i < numberOfAtoms; ++i)
        {
            const auto velocities = molecule.getAtomVelocities(i);
            const auto mass = molecule.getMass(i);

            momentum = velocities * mass;

            _momentumVector += momentum;
            _kineticEnergyAtomicVector += momentum * velocities;

            momentumSquared += momentum * momentum;
        }

        _kineticEnergyMolecularVector += momentumSquared / molecule.getMolMass();
    }

    _momentumVector *= _FS_TO_S_;

    _momentum = norm(_momentumVector);

    _kineticEnergyAtomicVector *= _KINETIC_ENERGY_FACTOR_;
    _kineticEnergyMolecularVector *= _KINETIC_ENERGY_FACTOR_;

    _kineticEnergy = sum(_kineticEnergyAtomicVector);
}

void PhysicalData::updateAverages(const PhysicalData &physicalData)
{
    _coulombEnergy += physicalData.getCoulombEnergy();
    _nonCoulombEnergy += physicalData.getNonCoulombEnergy();
    _temperature += physicalData.getTemperature();
    _momentum += physicalData.getMomentum();
    _kineticEnergy += physicalData.getKineticEnergy();
    _volume += physicalData.getVolume();
    _density += physicalData.getDensity();
    _virial += physicalData.getVirial();
    _pressure += physicalData.getPressure();
}

void PhysicalData::makeAverages(const double outputFrequency)
{
    _coulombEnergy /= outputFrequency;
    _nonCoulombEnergy /= outputFrequency;
    _temperature /= outputFrequency;
    _momentum /= outputFrequency;
    _kineticEnergy /= outputFrequency;
    _volume /= outputFrequency;
    _density /= outputFrequency;
    _virial /= outputFrequency;
    _pressure /= outputFrequency;
}