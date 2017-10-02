#ifndef TCP_H
#define TCP_H

#include <string>

class Tcp 
{
public:
    Tcp();
    void socket();
    void bind(int port);
    void connect(std::string host, int port);
    void listen(int queue = 5);
    Tcp* accept();
    void write(std::string message);
    std::string read();
    void close();
    
private:
    Tcp(int fd);

    int fd;
};

#endif //TCP_H