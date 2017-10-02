#ifndef NACKFRAME_H
#define NACKFRAME_H

#include <Frame.h>

class NackFrame : public Frame {
public:
    NackFrame(std::string id)
    {
        command = "NACK";
        addHeader("id", id);
    }
};

#endif //NACKFRAME_H