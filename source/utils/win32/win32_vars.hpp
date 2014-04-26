#ifndef __JULIA_CORE_UTILS_PLATFORM_WIN32_VARS_HPP__
#define __JULIA_CORE_UTILS_PLATFORM_WIN32_VARS_HPP__

#include"../utils.hpp"

#if (JPLATFORM_NAME == JPLATFORM_WINDOWS_32) || (JPLATFORM_NAME == JPLATFORM_WINDOWS_64)

JNAMESPACE_BEGIN

extern HWND		WindowHandle;
extern HDC		DeviceContextHandle;
extern HGLRC	GLContextHandle;

extern uint16_t	WindowSize[2];
extern uint16_t WindowPosition[2];
extern char		WindowTitle[32];
extern bool		Windowed;

JNAMESPACE_END

#endif//(JPLATFORM_NAME == JPLATFORM_WINDOWS_32) || (JPLATFORM_NAME == JPLATFORM_WINDOWS_64)
#endif//__JULIA_CORE_UTILS_PLATFORM_WIN32_VARS_HPP__