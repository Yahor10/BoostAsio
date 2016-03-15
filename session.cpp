//
// Created by ychabatarou on 29.2.16.
//

#include "session.h"

void session::read_hander(const boost::system::error_code& err,std::size_t bytes){

	if(!err){
		std::string s(buff.begin(),buff.end());
		printf("read  %s",s.c_str());
	}else{
		printf("error read");
	}

}
