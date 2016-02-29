//
// Created by ychabatarou on 29.2.16.
//

#include "server.h"
#include "boost/bind.hpp"
#include <boost/asio.hpp>

server::server(boost::asio::io_service& io_s,short port):acceptor(io_s,tcp::endpoint(tcp::v4(),port)),buff(1024){

	printf("start run server\n");
	session::pointer new_connection =
		session::create(io_s);

	acceptor.async_accept(new_connection->new_socket(),boost::bind(&server::accept_hander,this,boost::asio::placeholders::error));
}

void server::accept_hander(const boost::system::error_code& err)
{
	if(!err){
	printf("accept hander\n");
	session::pointer new_connection = session::create(acceptor.get_io_service());	
	acceptor.async_accept(new_connection->new_socket(),boost::bind(&server::accept_hander,this,boost::asio::placeholders::error));

	}
}

void server::read_hander(const boost::system::error_code& err,std::size_t bytes){

	if(bytes == 0){
		printf("0 bytes!!");
	}
	if(!err && bytes > 0){
		std::string s(buff.begin(),buff.end());
		printf("read handler %s\n", s.c_str());
	}
}

