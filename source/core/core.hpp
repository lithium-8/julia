#ifndef __JULIA_CORE_CORE_HPP__
#define __JULIA_CORE_CORE_HPP__

#include"../utils/utils.hpp"

JNAMESPACE_BEGIN

class JDLLEXPORT Core
{
public:
	Core& operator = (const Core& _core)
	{
		return (*this);
	}

	bool			init();
	void			start(bool(*_update)(float _timeDelta));
	void			shutdown();

	static Core*	create(const uint16_t& _version);
	void			release();
private:
	Core()
	{}

	Core(const Core& _core)
	{}

	~Core()
	{}
};

JNAMESPACE_END

#endif//__JULIA_CORE_CORE_HPP__