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

#ifndef _THERMOSTAT_HPP_

#define _THERMOSTAT_HPP_

namespace physicalData
{
    class PhysicalData;   // forward declaration
}

namespace simulationBox
{
    class SimulationBox;   // forward declaration
}

/**
 * @namespace thermostat
 */
namespace thermostat
{
    /**
     * @class Thermostat
     *
     * @brief Thermostat is a base class for all thermostats
     *
     * @details it provides a dummy function applyThermostat() which does only calculate the temperature
     *
     */
    class Thermostat
    {
      protected:
        double _temperature       = 0.0;
        double _targetTemperature = 0.0;

      public:
        Thermostat() = default;
        explicit Thermostat(const double targetTemperature) : _targetTemperature(targetTemperature) {}
        virtual ~Thermostat() = default;

        virtual void applyThermostat(simulationBox::SimulationBox &, physicalData::PhysicalData &);
        virtual void applyThermostatHalfStep(simulationBox::SimulationBox &, physicalData::PhysicalData &){};
        virtual void applyThermostatOnForces(simulationBox::SimulationBox &){};
    };

}   // namespace thermostat

#endif   // _THERMOSTAT_HPP_