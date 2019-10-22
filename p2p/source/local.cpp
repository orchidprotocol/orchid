/* Orchid - WebRTC P2P VPN Market (on Ethereum)
 * Copyright (C) 2017-2019  The Orchid Authors
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


#include "connection.hpp"
#include "local.hpp"

namespace orc {

task<Socket> Local::Associate(Sunk<> *sunk, const std::string &host, const std::string &port) {
    auto connection(std::make_unique<Connection<asio::ip::udp::socket>>(Context()));
    auto endpoint(co_await connection->Open(host, port));
    auto inverted(sunk->Wire<Inverted>(std::move(connection)));
    inverted->Open();
    co_return Socket(endpoint.address().to_string(), endpoint.port());
}

task<Socket> Local::Connect(U<Stream> &stream, const std::string &host, const std::string &port) {
    auto connection(std::make_unique<Connection<asio::ip::tcp::socket>>(Context()));
    auto endpoint(co_await connection->Open(host, port));
    stream = std::move(connection);
    co_return Socket(endpoint.address().to_string(), endpoint.port());
}

task<Socket> Local::Unlid(Sunk<Opening, BufferSewer> *sunk) {
    auto opening(sunk->Wire<Opening>());
    opening->Open({asio::ip::address_v4::any(), 0});
    co_return opening->Local();
}

S<Local> GetLocal() {
    static auto local(Make<Local>());
    return local;
}

}