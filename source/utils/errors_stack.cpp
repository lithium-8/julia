#include"errors_stack.hpp"
#include"../core/core.hpp"

JNAMESPACE_BEGIN

static std::stack<Error_t>	ErrStack;
static Error_t				ErrOK = { JERRCODE_OK, "OK", false };

const Error_t&	ErrorsStack::getLastError()
{
	if (!ErrStack.empty())
		return ErrStack.top();
	else
		return ErrOK;
}


void	ErrorsStack::pushError(const Error_t& _error)
{
	ErrStack.push(_error);
	Logger::write("________________________________________\n");
	if (_error._Critical == true)
	{
		Logger::write("Fatal Error: \n\tError Code: %d\n \tError Description: %s\n", _error._Code, _error._Description);
		Logger::write("Stoping application!", _error._Code, _error._Description);
		exit(0);
	}
	Logger::write("Error: \n\tError Code: %d\n \tError Description: %s\n", _error._Code, _error._Description);
	Logger::write("________________________________________\n");
}


void	ErrorsStack::deleteLastError()
{
	if (!ErrStack.empty())
		ErrStack.pop();
}

void	ErrorsStack::deleteAllError()
{
	for (int i = ErrStack.size(); i != 0; i--)
		ErrStack.pop();
}

uint32_t	ErrorsStack::countOfErrors()
{
	return ErrStack.size();
}

JNAMESPACE_END