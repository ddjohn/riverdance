#ifndef FRAME_H
#define FRAME_H

#include <string>
#include <map>
#include <utility>

class Frame 
{
public:
    std::string command;
    std::string body;  
    std::map<std::string, std::string> headers;
    
    std::string marshall();
    void addHeader(std::string key, std::string value);

private:
    
};

#endif //FRAME_H