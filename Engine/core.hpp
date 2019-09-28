#pragma once

#include <cstddef>

#ifdef NOVA_BUILD_DLL
/**
	 * \brief Defines the macro that is used to import/export DLL
	 */
	#define NOVA_API __declspec(dllexport)
#else
	#define NOVA_API __declspec(dllimport)
#endif


using Int8 = __int8;
using Int16 = __int16;
using Int32 = __int32;
using Int64 = __int64;

using Float = float;