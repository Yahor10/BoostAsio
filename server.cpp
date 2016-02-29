//
// Created by ychabatarou on 29.2.16.
//

#include "server.h"
#include "boost/bind.hpp"
#include <boost/asio.hpp>

server::server(boost::asio::io_service& io_s,short port):acceptor(io_s,tcp::endpoint(tcp::v4(),port)),_socket(io_s),buff(1024){

	printf("start run server\n");
	acceptor.async_accept(_socket,boost::bind(&server::accept_hander,this,boost::asio::placeholders::error));
}

void server::accept_hander(const boost::system::error_code& err)
{
	if(!err){
	printf("accept hander\n");



	_socket.async_read_some(boost::asio::buffer(buff,1024),boost::bind(&server::read_hander,this,boost::asio::placeholders::error,
				boost::asio::placeholders::bytes_transferred));



	acceptor.async_accept(_socket,boost::bind(&server::accept_hander,this,boost::asio::placeholders::error));

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

