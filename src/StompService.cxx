#include <StompService.h>
#include <Frame.h>
#include <ConnectedFrame.h>
#include <ConnectFrame.h>
#include <AckFrame.h>
#include <DisconnectFrame.h>
#include <ReceiptFrame.h>
#include <ErrorFrame.h>
#include <FrameFactory.h>
#include <TcpServer.h>
#include <Trace.h>

CLASS("StompService");

void StompService::callback(std::string message)
{
    METHOD("callback(std::string");

    Frame* temp = FrameFactory::parse(message);
    
    if(temp->command == "CONNECT")
    {
        ConnectFrame* frame = (ConnectFrame*)temp;
        if(frame->getAcceptVersion() == "1.2")
        {
            ConnectedFrame f("1.2");
            server->send(f.marshall());    
            state = ConnectionStates::CONNECTED;
        }
        else
        {
            std::string msg = "Wrong protocol version: " + frame->getAcceptVersion();
            ErrorFrame f(msg);
            server->send(f.marshall());                
        }
    }

    if(state != ConnectionStates::CONNECTED)
    {
        ErrorFrame f("Not connected");
        server->send(f.marshall());                
    }
    else 
    {

    if(temp->command == "DISCONNECT")
    {
        DisconnectFrame* frame = (DisconnectFrame*)temp;
        std::string receipt = frame->getReceiptId();

        ReceiptFrame f(receipt);
         server->send(f.marshall());
    }

    if(temp->command == "MESSAGE")
    {
        AckFrame frame("id1");
        server->send(frame.marshall());
    }
    
    }
    delete temp;
}
