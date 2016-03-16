//
// Created by ychabatarou on 29.2.16.
//

#include "session.h"
#include "clientFile.h"
#include "serialize_manager.h"
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/tmpdir.hpp>

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

#include <boost/serialization/base_object.hpp>
#include <boost/serialization/utility.hpp>
#include <boost/serialization/list.hpp>
#include <boost/serialization/assume_abstract.hpp>


void session::read_hander(const boost::system::error_code& err,std::size_t bytes){

	if(!err){
		std::string s(buff.begin(),buff.end());
		const clientFile f(s);

		serialize_manager manager;

		std::string filename(boost::archive::tmpdir());
		filename += "/demofile.txt";

		manager.save_client_file(f,filename.c_str());

		printf("read  %s",s.c_str());

	}else{
		printf("error read");
	}

}
