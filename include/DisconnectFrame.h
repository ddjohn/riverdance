#ifndef DISCONNECTFRAME_H
#define DISCONNECTFRAME_H

#include <Frame.h>

class DisconnectFrame : public Frame {
public:
    DisconnectFrame(std::string receipt)
    {
        command = "DISCONNECT";
        addHeader("receipt-id", receipt);
    }

    std::string getReceiptId() {return headers["receipt-id"];}
};

#endif //DISCONNECTFRAME_H