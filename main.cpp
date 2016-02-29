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
#include "boost/thread/thread.hpp"
#include "server.h"


void f(){   
	boost::asio::io_service service;
	server  myserver(service,3030);
	service.run();
}



int main(int argc, char* argv[])
{
	boost::thread_group d;;
	d.create_thread(f);
	d.join_all();

}
