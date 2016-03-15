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


using boost::asio::ip::tcp;
using boost::asio::placeholders::bytes_transferred;
using boost::asio::placeholders::error;

class session :public boost::enable_shared_from_this<session> {


	public:
		session(boost::asio::io_service& io_service):_socket(io_service),buff(1024){

		}

		  typedef boost::shared_ptr<session> pointer;

		    static pointer create(boost::asio::io_service& io_s)
				  {
					      return pointer(new session(io_s));
						    }

			  tcp::socket& socket()
				    {
						    return _socket;
							  }

			  void start()
			  {
				  _socket.async_read_some(boost::asio::buffer(buff,1024),boost::bind(&session::read_hander,this,error,bytes_transferred));
			  }

	private:
		tcp::socket _socket;
		std::vector<char>buff;
void read_hander(const boost::system::error_code& err,std::size_t bytes);

};


#endif //TESTBOOST_SESSION_H
