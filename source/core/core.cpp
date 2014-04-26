#include"core.hpp"

JNAMESPACE_BEGIN

bool Core::init()
{
	platformInit();
	platformWindowCreate();
	return true;
}

void Core::start(bool(*_update)(float _timeDelta))
{
	while (true)
	{
		platformUpdate();
		if (false == _update(0.0F))
			break;
	}
}

void Core::shutdown()
{
	platformWindowDestroy();
}

static Core* CoreInstance = NULL;

Core* Core::create(const uint16_t& _version)
{
	Logger::clear();

	if (CoreInstance != NULL)
	{
		Error_t err = { JERRCODE_CORE_INSTANCE_WAS_CREATED_EARLIER, "Instance of Core was created earlier", false };
		ErrorsStack::pushError(err);
	}

	if (_version != JVERSION)
	{
		Error_t err = { JERRCODE_INVALID_VERSION, "Invalid engine version", false };
		ErrorsStack::pushError(err);
	}
	CoreInstance = new Core();
	CoreInstance->init();
	return CoreInstance;
}


void Core::release()
{
	CoreInstance = NULL;
	delete this;
}


JNAMESPACE_END