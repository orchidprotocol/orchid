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


#ifndef ORCHID_MARKET_HPP
#define ORCHID_MARKET_HPP

#include "currency.hpp"
#include "integer.hpp"
#include "shared.hpp"
#include "task.hpp"
#include "updated.hpp"

namespace orc {

class Base;
class Chain;
struct Locator;

struct Market {
    const S<Chain> chain_;
    const Currency currency_;
    const S<Updated<uint256_t>> bid_;

    static task<Market> New(unsigned milliseconds, S<Chain> chain, Currency currency);
    static task<Market> New(unsigned milliseconds, uint256_t chain, const S<Base> &base, Locator locator, std::string currency);
};

}

#endif//ORCHID_MARKET_HPP
