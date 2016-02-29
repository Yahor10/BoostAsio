//
// Created by ychabatarou on 29.2.16.
//

#include "session.h"

session::session(boost::asio::io_service& service):_socket(service){

}

boost::asio::ip::tcp::socket& session::new_socket(){
	return _socket;
}


