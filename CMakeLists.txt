cmake_minimum_required(VERSION 3.3)
project(TestBoost)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lboost_thread -lboost_system")
set(SOURCE_FILES main.cpp server.cpp server.h session.cpp session.h)
set(Boost_USE_MULTITHREADED ON)
find_package(Boost COMPONENTS system filesystem thread REQUIRED)
add_executable(TestBoost ${SOURCE_FILES})

target_link_libraries(TestBoost
        ${Boost_FILESYSTEM_LIBRARY}
        ${Boost_SYSTEM_LIBRARY}
        ${Boost_REGEX_LIBRARY}
		${Boost_THREAD_LIBRARY}
        )
