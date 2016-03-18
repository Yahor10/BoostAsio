
// Created by ychabatarou on 29.2.16.
//
#include <cstdlib>
#include <iostream>
#include <memory>
#include <utility>
#include <boost/asio.hpp>
#include "session.h"
#include "boost/date_time/posix_time/posix_time.hpp" 

#include <boost/archive/tmpdir.hpp>

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

#include <boost/serialization/base_object.hpp>
#include <boost/serialization/utility.hpp>
#include <boost/serialization/list.hpp>
#include <boost/serialization/assume_abstract.hpp>
    using boost::posix_time::to_simple_string;

#ifndef TESTBOOST_CLIENTFILE_H
#define TESTBOOST_CLIENTFILE_H


class clientFile {

	public:
		clientFile(){
		}

		clientFile(std::string& s)
		{
			message = s;
			printf("message write %s\n ",message.c_str());
			
		}

		template<class Archive>
	    void serialize(Archive & ar, const unsigned int /* file_version */){
			        ar & message;
		}

	  friend std::ostream & operator<<(std::ostream &os, const clientFile &cf);
	    std::string message;

	private:
};

BOOST_SERIALIZATION_ASSUME_ABSTRACT(clientFile)
std::ostream& operator<<(std::ostream& os,const clientFile& cl){
	printf("invoke serialize operate \n");
	boost::gregorian::date current_date(boost::gregorian::day_clock::local_day());
	return  os <<"Message"<<cl.message<<"write in time"<<"";
}



#endif
