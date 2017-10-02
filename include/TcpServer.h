#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <functional>

class Tcp;
class TcpServer 
{
public:
    TcpServer(int port);
    void init();
    void addHandler(std::function<void(std::string)> callback);
    void send(std::string message);
    
private:
    Tcp* tcp;
    std::function<void(std::string)> callback;
};

#endif //TCPSERVER_H