#ifndef __JULIA_UTILS_ERRORS_STACK_HPP__
#define __JULIA_UTILS_ERRORS_STACK_HPP__

#include"../utils/utils.hpp"

JNAMESPACE_BEGIN

enum CodesOfErrors
{
	JERRCODE_OK									= 0x00,
	JERRCODE_INVALID_VERSION					= 0x01,
	JERRCODE_CORE_INSTANCE_WAS_CREATED_EARLIER	= 0x02,
	JERRCODE_PLATFORM_WINDOW_CREATE_FAILED		= 0x03
};

typedef struct
{
	CodesOfErrors	_Code;
	char*			_Description;
	bool			_Critical;
}Error_t;

class JDLLEXPORT ErrorsStack
{
public:
	static const Error_t&	getLastError();
	static void				pushError(const Error_t& _error);
	static void				deleteLastError();
	static void				deleteAllError();
	static uint32_t			countOfErrors();
private:
	ErrorsStack()
	{}

	ErrorsStack(const ErrorsStack& _core)
	{}

	~ErrorsStack()
	{}

	ErrorsStack& operator = (const ErrorsStack& _core)
	{
		return (*this);
	}
};

JNAMESPACE_END

#endif//__JULIA_UTILS_ERRORS_STACK_HPP__