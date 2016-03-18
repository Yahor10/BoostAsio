//
// Created by ychabatarou on 18.3.16.
//
#define BOOST_LOG_DYN_LINK 1

#include "logger.h"
#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>


namespace logging = boost::log;
namespace src = boost::log::sources;
namespace sinks = boost::log::sinks;
namespace keywords = boost::log::keywords;


logger::logger(){
    init();
    logging::add_common_attributes();
}
void logger::init(){
    logging::add_file_log("/home/ychabatarou/Downloads/gitProjects/BoostAsio/sample.log");
    logging::core::get()->set_filter
            (
                    logging::trivial::severity >= logging::trivial::info
            );

}

void logger::log_simple_message(std::string message)
{
    printf("write log message\n ");
    using namespace logging::trivial;
    src::severity_logger< severity_level > lg;

    BOOST_LOG_SEV(lg, info) <<message;
}