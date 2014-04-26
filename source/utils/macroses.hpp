#ifndef __JULIA_CORE_UTILS_MACROSES_HPP__
#define __JULIA_CORE_UTILS_MACROSES_HPP__

#include"utils.hpp"

#define JFREE(pointer)			if(pointer) free(pointer);		pointer = NULL;
#define JDELETE(pointer)		if(pointer) delete pointer;		pointer = NULL;
#define JDELETEARRAY(pointer)	if(pointer) delete[] pointer;	pointer = NULL;

#endif//__JULIA_CORE_UTILS_MACROSES_HPP__