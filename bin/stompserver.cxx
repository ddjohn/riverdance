#include <stdio.h>
#include <Frame.h>
#include <SendFrame.h>
#include <ConnectFrame.h>
#include <ErrorFrame.h>
#include <ConnectedFrame.h>
#include <SubscribeFrame.h>
#include <UnsubscribeFrame.h>
#include <AckFrame.h>
#include <TcpServer.h>
#include <StompService.h>

int main (int argc, char *argv[])
{
  TcpServer server(4040);

  StompService stomp(&server);  
  server.addHandler(std::bind(&StompService::callback, stomp, std::placeholders::_1));
  server.init(); 
  
  return 0;
}
