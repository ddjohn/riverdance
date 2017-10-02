#include <TcpServer.h>
#include <Tcp.h>
#include <Trace.h>

#include <unistd.h>

CLASS("TcpServer");

TcpServer::TcpServer(int port)
{
    METHOD("TcpServer");

    tcp = new Tcp();

    tcp->socket();
    tcp->bind(port);
    tcp->listen(5);
}

void TcpServer::init()
{
    METHOD("init()");

    while(true) 
    {
        Tcp* clientTcp = tcp->accept();

        int pid = fork();
        if(pid == 0) 
        {
            // client
            tcp->close();
            tcp = clientTcp;

            while(true)
            {
                std::string message = clientTcp->read();
                DEBUG("message: " << message);
                if(message == "")
                {
                    // Client dead or misbehaving
                    exit(0);
                }
                callback(message);
            }
        }
        else 
        {
            // server
            clientTcp->close();
        }
    }
}

void TcpServer::addHandler(std::function<void(std::string)> callback)
{
    METHOD("addHandler(std::function<void(std::string)>)");

    DEBUG("Callback registered");
    this->callback = callback;
}

void TcpServer::send(std::string message)
{
    METHOD("send(std::string)");
    
    tcp->write(message);
}
