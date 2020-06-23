#include <sstream>
#include <iostream>

#ifndef LOG_H
#define LOG_H

// Logging stuff
extern std::stringstream debugLogStream;

class Log
{
public:
	Log(const std::string &funcName)
	{
		debugLogStream << funcName << ": ";
	}
	
	template <class T>
	Log &operator<<(const T &v)
	{
		debugLogStream << v;
		return *this;
	}
	
	~Log()
	{
		debugLogStream << std::endl;
		printf("%s", debugLogStream.str().c_str());
		
		// Clear the stream
		debugLogStream.str("");
	}
};

#define DEBUGLOG Log(__FUNCTION__)

#endif
