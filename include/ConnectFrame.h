#ifndef CONNECTFRAME_H
#define CONNECTFRAME_H

#include <Frame.h>

class ConnectFrame : public Frame {
public:
    ConnectFrame(std::string version, std::string host)
    {
        command = "CONNECT";
        addHeader("accept-version", version);
        addHeader("host", host);
    }

    std::string getAcceptVersion() {return headers["accept-version"];}

};

#endif //CONNECTFRAME_H