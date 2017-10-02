#ifndef ACKFRAME_H
#define ACKFRAME_H

#include <Frame.h>

class AckFrame : public Frame {
public:
    AckFrame(std::string id)
    {
        command = "ACK";
        addHeader("id", id);
    }
};

#endif //ACKFRAME_H