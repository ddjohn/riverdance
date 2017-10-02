#ifndef MESSAGEFRAME_H
#define MESSAGEFRAME_H

#include <Frame.h>

class MessageFrame : public Frame {
public:
    MessageFrame(std::string subscription, std::string destination, std::string message)
    {
        command = "MESSAGE";
        addHeader("subscription", subscription);
        addHeader("destination", destination);
        addHeader("content-type", "text/plain");
        body = message;
    }
};

#endif //MESSAGEFRAME_H