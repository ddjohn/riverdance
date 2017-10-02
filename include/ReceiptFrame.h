#ifndef RECEIPTFRAME_H
#define RECEIPTFRAME_H

#include <Frame.h>

class ReceiptFrame : public Frame {
public:
    ReceiptFrame(std::string receipt)
    {
        command = "RECEIPT";
        addHeader("receipt-id", receipt);
    }
};

#endif //RECEIPTFRAME_H