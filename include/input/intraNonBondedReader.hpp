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

#ifndef _INTRA_NON_BONDED_READER_HPP_

#define _INTRA_NON_BONDED_READER_HPP_

#include <cstddef>   // for size_t
#include <fstream>   // for ifstream
#include <iosfwd>    // for ifstream
#include <string>    // for string

#include "typeAliases.hpp"

namespace input::intraNonBondedReader
{
    void               readIntraNonBondedFile(pq::Engine &);
    [[nodiscard]] bool isNeeded(const pq::Engine &engine);

    /**
     * @class IntraNonBondedReader
     *
     * @brief reads the intra non bonded interactions from the intraNonBonded
     * file
     */
    class IntraNonBondedReader
    {
       private:
        std::string   _fileName;
        std::ifstream _fp;

        size_t _lineNumber = 1;

        pq::Engine &_engine;

       public:
        IntraNonBondedReader(const std::string &fileName, pq::Engine &engine);

        void                 read();
        void                 processMolecule(const size_t moleculeType);
        void                 checkDuplicates() const;
        [[nodiscard]] size_t findMoleculeType(const std::string &) const;

        void setFileName(const std::string_view &fileName);
        void reInitializeFp();
    };

}   // namespace input::intraNonBondedReader

#endif   // _INTRA_NON_BONDED_READER_HPP_