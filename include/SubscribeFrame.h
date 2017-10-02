#ifndef SUBSCRIBEFRAME_H
#define SUBSCRIBEFRAME_H

#include <Frame.h>

enum class SubscribeFrameAcknowledges 
{ 
    AUTO, CLIENT, CLIENT_INDIVIDUAL
};

class SubscribeFrame : public Frame {
public:
    SubscribeFrame(std::string id, std::string destination, SubscribeFrameAcknowledges ack)
    {
        command = "SUBSCRIBE";
        addHeader("id", id);
        addHeader("destination", destination);
        addHeader("ack", "auto");  //TODO
    }
};

#endif //SUBSCRIBEFRAME_H