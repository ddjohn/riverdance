#ifndef TRACE_H
#define TRACE_H

#include <string>
#include <stdexcept>
#include <sstream>

#define CLASS(CLASS) \
	static const char* abcClass = CLASS; 

#define METHOD(METHOD) \
	Trace abcTrace(abcClass, METHOD, __FILE__, __LINE__);

#define INFO(MSG) \
	{ \
		std::stringstream str; \
		str << MSG; \
		abcTrace.info(str.str()); \
    }
    
#define DEBUG(MSG) \
	{ \
		std::stringstream str; \
		str << MSG; \
		abcTrace.debug(str.str()); \
	}

#define EXCEPTION(EXCEPTION) \
	throw std::logic_error(EXCEPTION);

class Trace {

public:
	Trace(std::string clazz, std::string meths, std::string file, int line);
	~Trace();

    void info(std::string msg);
	void debug(std::string msg);
    
private:
	std::string clazz;
	std::string method;
	static int scope;
};

#endif