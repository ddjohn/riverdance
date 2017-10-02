#ifndef STOMPSERVICE_H
#define STOMPSERVICE_H

#include <string>

class TcpServer;
class StompService
{
public:
    StompService(TcpServer* tcp) : server{tcp} {};
    void callback(std::string message);
    
private:
    TcpServer* server;
};

#endif //STOMPSERVICE_H