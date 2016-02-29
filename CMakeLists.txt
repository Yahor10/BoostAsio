cmake_minimum_required(VERSION 3.3)
project(TestBoost)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lboost_system")
set(SOURCE_FILES main.cpp server.cpp server.h session.cpp session.h)

find_package(Boost COMPONENTS system filesystem REQUIRED)

add_executable(TestBoost ${SOURCE_FILES})

target_link_libraries(TestBoost
        ${Boost_FILESYSTEM_LIBRARY}
        ${Boost_SYSTEM_LIBRARY}
        ${Boost_REGEX_LIBRARY}
        )