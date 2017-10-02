#include <Trace.h>
#include <iostream>
#include <stdio.h>

int Trace::scope = 0;

Trace::Trace(std::string clazz, std::string method, std::string file, int line) {
	this->clazz = clazz;
	this->method = method;

	char buf[256];
	sprintf(buf, "--> (%d) %s::%s (%s, line %d)", ++scope, clazz.c_str(), method.c_str(), file.c_str(), line);
    
    if(getenv("TRACE"))
    {
        std::cerr << buf << std::endl;        
    }
}

Trace::~Trace() {
	char buf[256];
	sprintf(buf, "<-- (%d) %s::%s", scope--, clazz.c_str(), method.c_str());

    if(getenv("TRACE"))
    {
        std::cerr << buf << std::endl;
    }
}
	
void Trace::info(std::string msg) {
	char buf[256];

    if(getenv("TRACE"))
    {
        sprintf(buf, "### (%d) %s::%s %s", scope, clazz.c_str(), method.c_str(), msg.c_str());
        std::cerr << buf << std::endl;
    }
    else
    {
        sprintf(buf, "### %s", msg.c_str());
        std::cerr << buf << std::endl;        
    }
}
	
void Trace::debug(std::string msg) {
	char buf[256];

    if(getenv("TRACE"))
    {
        sprintf(buf, "### (%d) %s::%s %s", scope, clazz.c_str(), method.c_str(), msg.c_str());
        std::cerr << buf << std::endl;
    }
}
