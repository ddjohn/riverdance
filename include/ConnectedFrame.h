#ifndef CONNECTEDFRAME_H
#define CONNECTEDFRAME_H

#include <Frame.h>

class ConnectedFrame : public Frame {
public:
    ConnectedFrame(std::string version)
    {
        command = "CONNECTED";
        addHeader("accept-version", version);
    }
};

#endif //CONNECTEDFRAME_H