//
// reference_counted.cpp
// ~~~~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2015 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <boost/asio.hpp>
#include <iostream>
#include <memory>
#include <utility>
#include <vector>

#include <boost/bind.hpp>
#include "boost/thread.hpp"
#include "tcp_server_node.h"
#include "tcp_server.h"


void f(){   

}


int main(int argc, char* argv[])
{
	tcp_server server;
	server.createNode(3030);
	server.createNode(3031);
	server.startService();

	return 0;
}
