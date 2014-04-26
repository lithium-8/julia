#ifndef __JULIA_CORE_UTILS_INCLUDES_HPP__
#define __JULIA_CORE_UTILS_INCLUDES_HPP__

#include"defines.hpp"

#if (JPLATFORM_NAME == JPLATFORM_WINDOWS_32) || (JPLATFORM_NAME == JPLATFORM_WINDOWS_64)
#	include<Windows.h>
#	include<gl/GL.h>
#	include"../exdep/GL/glext.h"
#	include"../exdep/GL/wglext.h"
#endif//(JPLATFORM_NAME == JPLATFORM_WINDOWS_32) || (JPLATFORM_NAME == JPLATFORM_WINDOWS_64)

#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include<stdint.h>
#include<time.h>
#include<math.h>
#include<assert.h>
#include<string.h>

#include<stack>

#endif//__JULIA_CORE_UTILS_INCLUDES_HPP__