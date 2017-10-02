#include <Frame.h>
#include <Trace.h>

CLASS("Frame");

std::string Frame::marshall()
{
    METHOD("marshall()");

    std::string temp = command + "\n";
    for(auto header : headers)
    {
        temp += header.first + ":" + header.second + "\n";
    }
    temp += "\n";
    temp += body;
    return temp + "\0";
}

void Frame::addHeader(std::string key, std::string value)
{
    METHOD("addHeader(std::string, std::string)");
    
    DEBUG("Add header " << key << ":" << value);
//    headers.push_back(std::make_pair(key, value));
//    headers.insert(std::make_pair(key, value));
    headers[key] = value;
}
