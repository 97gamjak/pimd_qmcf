/*****************************************************************************
<GPL_HEADER>

    PIMD-QMCF
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

#ifndef _SIMULATION_BOX_SETUP_HPP_

#define _SIMULATION_BOX_SETUP_HPP_

namespace engine
{
    class Engine;
}   // namespace engine

namespace setup::simulationBox
{
    void setupSimulationBox(engine::Engine &);
    void writeSetupInfo(engine::Engine &);

    /**
     * @class SetupSimulationBox
     *
     * @brief Setup simulation box
     *
     */
    class SimulationBoxSetup
    {
      private:
        engine::Engine &_engine;

      public:
        explicit SimulationBoxSetup(engine::Engine &engine) : _engine(engine){};

        void setup();

        void setAtomNames();
        void setAtomTypes();
        void setExternalVDWTypes();
        void setPartialCharges();

        void setAtomMasses();
        void setAtomicNumbers();

        void calculateMolMasses();
        void calculateTotalCharge();

        void checkBoxSettings();
        void checkRcCutoff();

        void initVelocities();
    };

}   // namespace setup::simulationBox

#endif   // _SIMULATION_BOX_SETUP_HPP_