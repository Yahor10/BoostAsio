//
// Created by ychabatarou on 21.3.16.
//

#ifndef TESTBOOST_TCP_SERVER_H
#define TESTBOOST_TCP_SERVER_H


#include <boost/asio/io_service.hpp>
#include <boost/thread.hpp>
#include "tcp_server_node.h"

class tcp_server {


public:


    tcp_server() {

    }


public:

    void createNode(int port){
        _ports.push_back(port);
    }

    void startNode(){
        printf("trying to start node !\n");
        tcp_server_node node(service,_ports[_thread_count]);
        _thread_count++;
        service.run();
    }

    void startService(){
        std::vector<boost::shared_ptr<boost::thread> > threads;

        for(int i = 0; i < _ports.size();i++){
            printf("try to init %d\n",_ports[i]);
            boost::shared_ptr<boost::thread> thread(new boost::thread(
                    boost::bind(&tcp_server::startNode, this)));
            threads.push_back(thread);
        }

        for(int i = 0; i < _ports.size();i++){
            threads[i]->join();
        }
    // Wait for all threads in the pool to exit.


    }

private:
    boost::asio::io_service service;
    std::vector<int>_ports;
    int _thread_count = 0;
};


#endif //TESTBOOST_TCP_SERVER_H
