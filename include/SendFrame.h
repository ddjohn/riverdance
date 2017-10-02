#ifndef SENDFRAME_H
#define SENDFRAME_H

#include <Frame.h>

class SendFrame : public Frame {
public:
    SendFrame(std::string destination, std::string message)
    {
        command = "SEND";
        addHeader("destination", destination);
        addHeader("content-type", "text/plain");
        body = message;
    }
};

#endif //SENDFRAME_H