cmake_minimum_required(VERSION 3.3)
project(TestBoost)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread -lboost_thread -lboost_system -lboost_serialization -lboost_log")
set(SOURCE_FILES main.cpp server.cpp server.h session.cpp session.h logging/logger.cpp logging/logger.h)
set(Boost_USE_MULTITHREADED ON)
find_package(Boost COMPONENTS system log filesystem thread serialization REQUIRED)
add_executable(TestBoost ${SOURCE_FILES})

target_link_libraries(TestBoost
        ${Boost_FILESYSTEM_LIBRARY}
        ${Boost_SYSTEM_LIBRARY}
        ${Boost_REGEX_LIBRARY}
		${Boost_THREAD_LIBRARY}
		${Boost_LOG_LIBRARY}
		${Boost_SERIALIZATION_LIBRARY}
        )
