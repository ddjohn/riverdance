#include <TcpClient.h>
#include <Tcp.h>
#include <Trace.h>

CLASS("TcpClient");

TcpClient::TcpClient(std::string host, int port)
{
    METHOD("TcpClient(std::string, int)");

    tcp = new Tcp();

    tcp->socket();
    tcp->connect(host, port);
}

void TcpClient::send(std::string message)
{
    METHOD("send(std::string)");

    tcp->write(message);
}

std::string TcpClient::receive()
{
    METHOD("receive()");

    return tcp->read();
}

void TcpClient::close()
{
    METHOD("close()");

    tcp->close();
}
