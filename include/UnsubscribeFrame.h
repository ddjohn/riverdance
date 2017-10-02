#ifndef UNSUBSCRIBEFRAME_H
#define UNSUBSCRIBEFRAME_H

#include <Frame.h>

class UnsubscribeFrame : public Frame {
public:
    UnsubscribeFrame(std::string id)
    {
        command = "UNSUBSCRIBE";
        addHeader("id", id);
    }
};

#endif //UNSUBSCRIBEFRAME_H