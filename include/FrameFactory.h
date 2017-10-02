#ifndef FRAMEFACTORY_H
#define FRAMEFACTORY_H

#include <string>

class Frame;
class FrameFactory 
{
public:
    static Frame* parse(std::string frame);
};

#endif //FRAMEFACTORY_H