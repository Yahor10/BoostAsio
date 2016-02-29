//
// Created by ychabatarou on 29.2.16.
//
#include <cstdlib>
#include <iostream>
#include <memory>
#include <utility>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

#ifndef TESTBOOST_SERVER_H
#define TESTBOOST_SERVER_H


class server {

	tcp::acceptor acceptor;
	tcp::socket _socket;

	std::vector<char>buff;
	public:
	server(boost::asio::io_service& io_s,short port);

	private:
	void accept_hander(const boost::system::error_code& err);

	void read_hander(const boost::system::error_code& err,std::size_t bytes);
};


#endif //TESTBOOST_SERVER_H
