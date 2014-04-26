#include"win32_vars.hpp"
#include"../platform.hpp"

JNAMESPACE_BEGIN

HWND		WindowHandle;
HDC			DeviceContextHandle;
HGLRC		GLContextHandle;

uint16_t	WindowSize[2];
uint16_t	WindowPosition[2];
char		WindowTitle[32];
bool		Windowed;

void platformInit()
{
	WindowHandle = NULL;
	DeviceContextHandle = NULL;
	GLContextHandle = NULL;
	WindowSize[0] = 800;
	WindowSize[1] = 600;
	WindowPosition[0] = 0;
	WindowPosition[1] = 0;
	strcpy(WindowTitle, "Julia Engine");
	Windowed = true;
}

JNAMESPACE_END