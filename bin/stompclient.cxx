#include <stdio.h>
#include <Frame.h>
#include <SendFrame.h>
#include <ConnectFrame.h>
#include <ErrorFrame.h>
#include <ConnectedFrame.h>
#include <DisconnectFrame.h>
#include <SubscribeFrame.h>
#include <UnsubscribeFrame.h>
#include <AckFrame.h>
#include <TcpClient.h>
#include <Trace.h>
#include <MessageFrame.h>

CLASS("stompclient");

int main(int argc, char* argv[])
{
  METHOD("main()");

  TcpClient server("localhost", 4040);

  {
    ConnectFrame frame("1.2", "client");
    server.send(frame.marshall());
  }

  INFO("message: " + server.receive());

  {
    MessageFrame frame("id1", "/queue", "My message\nBy world\nTest");
    server.send(frame.marshall());
  }

  INFO("message: " + server.receive());

  {
    DisconnectFrame frame("receipt1");
    server.send(frame.marshall());
  }

  INFO("message: " + server.receive());

  server.close();

return 0;
}
