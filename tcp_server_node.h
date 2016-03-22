
// Created by ychabatarou on 29.2.16.
//
#include <cstdlib>
#include <iostream>
#include <memory>
#include <utility>
#include <boost/asio.hpp>
#include "session.h"

using boost::asio::ip::tcp;

#ifndef TESTBOOST_SERVER_H
#define TESTBOOST_SERVER_H


class tcp_server_node{

	tcp::acceptor acceptor;

	std::vector<char>buff;

	int _node_port;

	public:
	tcp_server_node(boost::asio::io_service& io_s, short port);

	void startAsync();
	private:
	void accept_hander(session* s,const boost::system::error_code& err);

	void read_hander(const boost::system::error_code& err,std::size_t bytes);
	session* s;
};


#endif //TESTBOOST_SERVER_H
