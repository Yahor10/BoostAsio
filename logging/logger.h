//
// Created by ychabatarou on 18.3.16.
//

#ifndef TESTBOOST_LOGGER_H
#define TESTBOOST_LOGGER_H
#include <cstdlib>
#include <iostream>

class logger {

public:
    logger();
void init();
void log_simple_message(std::string message);
};


#endif //TESTBOOST_LOGGER_H
