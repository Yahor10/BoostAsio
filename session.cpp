//
// Created by ychabatarou on 29.2.16.
//

#include "session.h"
#include "clientFile.h"
#include "serialize_manager.h"


void session::read_hander(const boost::system::error_code& err,std::size_t bytes){

	if(!err){

		session_count++;
		printf("start session %d \n",session_count);

		std::string s(buff.begin(),buff.end());

		// TODO log all data
		log1->log_simple_message(s);


		_socket.async_read_some(boost::asio::buffer(buff,512),boost::bind(&session::read_hander,this,error,bytes_transferred));


	}else{
		printf("error read");
	}

}
