//
// Created by ychabatarou on 29.2.16.
//

#include "tcp_server_node.h"
#include "boost/bind.hpp"
#include <boost/asio.hpp>
#include <boost/asio/steady_timer.hpp>
#include <chrono>
#include <boost/make_shared.hpp>
#include <boost/thread.hpp>

tcp_server_node::tcp_server_node(boost::asio::io_service& io_s, short port): acceptor(io_s, tcp::endpoint(tcp::v4(), port)), buff(512),_node_port(port){

	printf("start run node %d\n" , port);

	session *s = new session(io_s);
	acceptor.async_accept(s->socket(),boost::bind(&tcp_server_node::accept_hander,this, s, boost::asio::placeholders::error));


//	boost::bind(&tcp_server_node::f, this);
//
//	io_s.post(boost::bind(&tcp_server_node::f, this));


}


void tcp_server_node::startAsync() {
	printf("start async!");

}

void tcp_server_node::accept_hander(session* s, const boost::system::error_code& err)
{
	if(!err)
	{
	printf("accept hander _node_port :%d\n",_node_port);

	s->start();
	s = new session(acceptor.get_io_service());
	acceptor.async_accept(s->socket(),boost::bind(&tcp_server_node::accept_hander, this, s, boost::asio::placeholders::error));
	}else{
		printf("handle err message  %d\n",err.value());
		printf("handle err message  %s\n",err.message().c_str());
	}
}

