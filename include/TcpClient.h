#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <string>

class Tcp;
class TcpClient
{
public:
    TcpClient(std::string host, int port);
    void send(std::string message);
    std::string receive();
    void close();
    
private:
    Tcp* tcp;
};

#endif //TCPCLIENT_H