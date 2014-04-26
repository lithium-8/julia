#ifndef __JULIA_CORE_UTILS_PLATFORM_HPP__
#define __JULIA_CORE_UTILS_PLATFORM_HPP__

#include"utils.hpp"

JNAMESPACE_BEGIN

extern void JDLLEXPORT platformInit();

extern bool JDLLEXPORT platformWindowCreate();
extern void JDLLEXPORT platformWindowDestroy();

extern bool JDLLEXPORT platformGLInit();
extern void JDLLEXPORT platformGLDestroy();

extern void JDLLEXPORT platformUpdate();

JNAMESPACE_END

#endif//__JULIA_CORE_UTILS_PLATFORM_WIN32_HPP__