#include"logger.hpp"

JNAMESPACE_BEGIN

static const char NameOfLogFile[] = "julia/log.txt";

void Logger::clear()
{
	FILE* file = fopen(NameOfLogFile, "wt");
	if (file != NULL)
	{
		fclose(file);
	}
}

void Logger::write(const char* _format, ...)
{
	FILE* file = fopen(NameOfLogFile, "a+");
	if (file != NULL)
	{
		va_list args = NULL;
		va_start(args, _format);
		vfprintf(file, _format, args);
		va_end(args);
		fclose(file);
	}
}

JNAMESPACE_END