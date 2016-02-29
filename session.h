//
// Created by ychabatarou on 29.2.16.
//
#include <boost/asio.hpp>
#include <iostream>
#include <memory>
#include <utility>
#include <vector>

#include <boost/bind.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/shared_ptr.hpp>

#ifndef TESTBOOST_SESSION_H
#define TESTBOOST_SESSION_H


class session :public boost::enable_shared_from_this<session> {

	public:
	typedef boost::shared_ptr<session> pointer;

	static pointer create(boost::asio::io_service& io_service){
		printf("create pointer");
		return pointer(new session(io_service));
	}

	boost::asio::ip::tcp::socket& new_socket();

	session(boost::asio::io_service& service);

	private:
	boost::asio::ip::tcp::socket _socket;
};


#endif //TESTBOOST_SESSION_H
