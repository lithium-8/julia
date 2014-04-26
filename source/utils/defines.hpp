#ifndef __JULIA_CORE_UTILS_DEFINES_HPP__
#define __JULIA_CORE_UTILS_DEFINES_HPP__

#define JVERSION				0x0001 //0xAABB - AA -Старшая версия, BB - младшая версия

#define JPLATFORM_WINDOWS_32	0
#define JPLATFORM_LINUX_32		1
#define JPLATFORM_WINDOWS_64	2
#define JPLATFORM_LINUX_64		3

#if defined(_WIN32) && !defined(JPLATFORM_NAME)
#	if defined(_WIN64)
#		define JPLATFORM_NAME JPLATFORM_WINDOWS_64
#	else
#		define JPLATFORM_NAME JPLATFORM_WINDOWS_32
#	endif//_WIN64
#	define _CRT_SECURE_NO_WARNINGS//Visual Studio, узбагойзя!
#endif//_WIN32

#if _USRDLL
#	define JDLLEXPORT __declspec(dllexport)
#else
#	define JDLLEXPORT
#endif//_USRDLL

#define JNAMESPACE_BEGIN	namespace julia{
#define JNAMESPACE_END		}//namespace julia

#endif//__JULIA_CORE_UTILS_DEFINES_HPP__