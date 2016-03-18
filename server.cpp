//
// Created by ychabatarou on 29.2.16.
//

#include "server.h"
#include "boost/bind.hpp"
#include <boost/asio.hpp>
#include <boost/asio/steady_timer.hpp>
#include <chrono>

server::server(boost::asio::io_service& io_s,short port):acceptor(io_s,tcp::endpoint(tcp::v4(),port)),buff(1024){

	printf("start run server\n");

	session* s = new session(io_s);

	acceptor.async_accept(s->socket(),boost::bind(&server::accept_hander,this,s,boost::asio::placeholders::error));


	boost::bind(&server::f,this);

	io_s.post(boost::bind(&server::f,this));



}

void server::accept_hander(session* s,const boost::system::error_code& err)
{
	if(!err)
	{
	printf("accept hander\n");
	s->start();
	s = new session(acceptor.get_io_service());

	acceptor.async_accept(s->socket(),boost::bind(&server::accept_hander,this,s,boost::asio::placeholders::error));
	}else{
		printf("handle err");
	}
}

void server::f(){
	printf("f");
}


