#include <FrameFactory.h>
#include <Frame.h>
#include <ConnectFrame.h>
#include <sstream>
//#include <cstream>
#include <string.h>
//#include <iostream>
#include <Trace.h>

CLASS("FrameFactory");

Frame* FrameFactory::parse(std::string frameAsString)
{
    METHOD("parse(std::string)");

    Frame* frame = new Frame();

    std::istringstream istream(frameAsString);    
    std::string line;

    // Commandline
    std::getline(istream, line);
    DEBUG("Parsing command " << line);
    INFO(line)
    frame->command = line;
    
    // Headers
    while(true)
    {
        std::getline(istream, line);
        if(line == "")
        {
            break;
        }

        char* tokens = (char*)line.c_str();
        char* key = strtok(tokens, ":");
        char* value = strtok(NULL, ":");
        DEBUG("Parsing header " << key << " - " << value);
        frame->addHeader(key, value);
    }

    // Body
    std::ostringstream sstream;
    sstream << istream.rdbuf();
    frame->body = sstream.str();
    DEBUG("Parsing body " << frame->body);
    
    return frame;
}