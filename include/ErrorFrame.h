#ifndef ERRORFRAME_H
#define ERRORFRAME_H

#include <Frame.h>

class ErrorFrame : public Frame {
public:
    ErrorFrame(std::string message)
    {
        command = "ERROR";
        body = message;
    }
};

#endif //ERRORFRAME_H