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

#ifndef __DEVICE_HPP__
#define __DEVICE_HPP__

#include <cstddef>   // for size_t
#include <string>
#include <vector>

#include "deviceConfig.hpp"

namespace device
{

    class Device
    {
       private:
        std::vector<std::string> _errorMsgs;

       public:
        Device()          = default;
        virtual ~Device() = default;

        void checkErrors(const std::string& msg = "");

        template <typename T>
        void deviceMalloc(T** ptr, size_t size);

        template <typename T>
        void deviceFree(T* ptr);
    };

}   // namespace device

#include "device.tpp.hpp"   // DO NOT MOVE THIS LINE!!!

#endif   // __DEVICE_HPP__