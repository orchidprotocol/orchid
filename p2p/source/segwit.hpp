/* Orchid - WebRTC P2P VPN Market (on Ethereum)
 * Copyright (C) 2017-2020  The Orchid Authors
*/

/* GNU Affero General Public License, Version 3 {{{ */
/*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.

 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
**/
/* }}} */


#ifndef ORCHID_SEGWIT_HPP
#define ORCHID_SEGWIT_HPP

#include <string>

#include "buffer.hpp"

namespace orc {

std::string ToSegwit(const std::string &prefix, const std::optional<uint8_t> &version, const Buffer &data);
std::pair<std::string, Beam> FromSegwit(const std::string &data);

}

#endif//ORCHID_SEGWIT_HPP
