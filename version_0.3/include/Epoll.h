//
// Created by marvinle on 2019/2/26 5:11 PM.
//

#ifndef WEBSERVER_EPOLL_H
#define WEBSERVER_EPOLL_H

#include <sys/epoll.h>
#include <iostream>
#include <vector>
#include <unordered_map>

#include "HttpData.h"
#include "Socket.h"
#include "Timer.h"

using namespace timer;

class Epoll {

public:

    static int init(int max_events);
    static int addfd(int epoll_fd, int fd, __uint32_t events, std::shared_ptr<http::HttpData>);
    static int modfd(int epoll_fd, int fd, __uint32_t events, std::shared_ptr<http::HttpData>);
    static int delfd(int epoll_fd, int fd, __uint32_t events);
    static std::vector<std::shared_ptr<http::HttpData>> poll(const nsocket::ServerSocket &serverSocket, int max_event, int timeout);
    static void handleConnection(const nsocket::ServerSocket &serverSocket);

public:
    static std::unordered_map<int,std::shared_ptr<http::HttpData>>  httpDataMap;
    static const  int MAX_EVENTS;
    static epoll_event *events;
    static TimerManager timerManager;
    const static __uint32_t DEFAULT_EVENTS;

};

#endif //WEBSERVER_EPOLL_H
