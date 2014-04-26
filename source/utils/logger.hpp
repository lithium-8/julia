#ifndef __JULIA_CORE_UTILS_LOGGER_HPP__
#define __JULIA_CORE_UTILS_LOGGER_HPP__

#include"utils.hpp"

JNAMESPACE_BEGIN

class JDLLEXPORT Logger
{
public:
	static void clear();
	static void write(const char* _format, ...);
private:
	Logger()
	{
		Logger::clear();
	}

	Logger(const Logger& _core)
	{}

	~Logger()
	{}

	Logger& operator = (const Logger& _core)
	{
		return (*this);
	}
};

JNAMESPACE_END

#endif//__JULIA_CORE_UTILS_LOGGER_HPP__