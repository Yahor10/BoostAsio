//
// Created by ychabatarou on 29.2.16.
//

#include "session.h"
#include "clientFile.h"
#include "serialize_manager.h"

#if defined(_MSC_VER) || defined(__MINGW32__) //__MINGW32__ should goes before __GNUC__
#define JL_SIZE_T_SPECIFIER    "%Iu"
  #define JL_SSIZE_T_SPECIFIER   "%Id"
  #define JL_PTRDIFF_T_SPECIFIER "%Id"
#elif defined(__GNUC__)
#define JL_SIZE_T_SPECIFIER    "%zu"
#define JL_SSIZE_T_SPECIFIER   "%zd"
#define JL_PTRDIFF_T_SPECIFIER "%zd"
#else
// TODO figure out which to use.
  #if NUMBITS == 32
    #define JL_SIZE_T_SPECIFIER    something_unsigned
    #define JL_SSIZE_T_SPECIFIER   something_signed
    #define JL_PTRDIFF_T_SPECIFIER something_signed
  #else
    #define JL_SIZE_T_SPECIFIER    something_bigger_unsigned
    #define JL_SSIZE_T_SPECIFIER   something_bigger_signed
    #define JL_PTRDIFF_T_SPECIFIER something-bigger_signed
  #endif
#endif

void session::read_hander(const boost::system::error_code& err,std::size_t bytes){

	if(!err){

		session_count++;
		printf("The size of a is " JL_SIZE_T_SPECIFIER " bytes", bytes);

//		std::string byteArray(buff.begin(),buff.end());

		    unsigned long int timeStamp,hash = 0;
		timeStamp  = ((unsigned int) buff[0]) << 24;
		timeStamp |= ((unsigned int) buff[1]) << 16;
		timeStamp |= ((unsigned int) buff[2]) << 8;
		timeStamp |= ((unsigned int) buff[3]);

		hash  = ((unsigned int) buff[4]) << 24;
		hash |= ((unsigned int) buff[5]) << 16;
		hash |= ((unsigned int) buff[6]) << 8;
		hash |= ((unsigned int) buff[7]);


		printf("timeStamp : %ud\n" ,timeStamp);
		printf("hash : %ud\n" ,hash);

		printf("write start \n");
		std::string t = "message from first client";
//		boost::asio::async_write(_socket, boost::asio::buffer(t, t.length()), boost::bind(&session::write_handler,this,error,bytes_transferred));
		boost::asio::write(_socket,boost::asio::buffer(t, t.length()));
		printf("write finish\n");

		_socket.async_read_some(boost::asio::buffer(buff,bytes),boost::bind(&session::read_hander,this,error,bytes_transferred));



	}else{
		printf("read error %s \n ",err.message().c_str());
		printf("read error %d \n ",err.value());
	}
}

void session::write_handler(const boost::system::error_code &error, std::size_t bytes_transferred) {
	printf("write handler\n");

}
