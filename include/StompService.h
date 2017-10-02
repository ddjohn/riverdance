#ifndef STOMPSERVICE_H
#define STOMPSERVICE_H

#include <string>

enum class ConnectionStates
{
    CONNECTED, DISCONNECTED
};

class TcpServer;
class StompService
{
public:
    StompService(TcpServer* tcp) : server{tcp}, state{ConnectionStates::DISCONNECTED} {};
    void callback(std::string message);
    
private:
    TcpServer* server;
    ConnectionStates state;
};

#endif //STOMPSERVICE_H