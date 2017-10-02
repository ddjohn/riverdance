#include <Tcp.h>
#include <Trace.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <netdb.h>
#include <string.h>

CLASS("Tcp");

#define BUFFER_SIZE 256

Tcp::Tcp() 
{
    METHOD("Tcp()");
}

Tcp::Tcp(int fd): fd{fd}
{
    METHOD("Tcp(int)");
}

void Tcp::socket()
{
    METHOD("socket()");

    fd = ::socket(AF_INET, SOCK_STREAM, 0);
    DEBUG("socket: " << fd);

    if(fd < 0)
    {
        EXCEPTION("Could not create socket");
    }
}

void Tcp::bind(int port) 
{
    METHOD("bind(int)");

    struct sockaddr_in server;
    bzero((char*)&server, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = INADDR_ANY;
    int res = ::bind(fd, (struct sockaddr*)&server, sizeof(server));
    DEBUG("bind: " << res);

    if(res < 0)
    {
        EXCEPTION("Could not bind to port");
    }
}

void Tcp::connect(std::string host, int port)
{
    METHOD("connect(std::string, int)");

    struct hostent* serverentry = gethostbyname(host.c_str());
    
    struct sockaddr_in server;
    bzero((char*)&server, sizeof(server));
    server.sin_family = AF_INET;
    bcopy((char *)serverentry->h_addr, (char*)&server.sin_addr.s_addr, serverentry->h_length);
    server.sin_port = htons(port);

    int res = ::connect(fd, (struct sockaddr*)&server, sizeof(server));
    DEBUG("connect: " << res);

    if(res < 0)
    {
        EXCEPTION("Could not connect to server");
    }
}

void Tcp::listen(int queue)
{
    METHOD("listen(int)");

    ::listen(fd, queue);
}

Tcp* Tcp::accept()
{
    METHOD("accept()");
    
    struct sockaddr_in client;
    socklen_t length = sizeof(client);
    int clientfd = ::accept(fd, (struct sockaddr*)&client, &length);
    DEBUG("accept: " << clientfd);        
    

    return new Tcp(clientfd);
}

void Tcp::write(std::string message) 
{
    METHOD("write(std::string)");
    
    int n = ::write(fd, message.c_str(), message.size());
    DEBUG("write: " << n);        
}

std::string Tcp::read() 
{
    METHOD("read()");
    
    char buffer[BUFFER_SIZE + 1];    
    bzero(buffer, BUFFER_SIZE+1);

    int n = ::read(fd, buffer, BUFFER_SIZE);
    DEBUG("read: " << n);        
    
    buffer[n] = '\0';
    return buffer;
}

void Tcp::close()
{
    METHOD("close()");
    
    ::close(fd);
}