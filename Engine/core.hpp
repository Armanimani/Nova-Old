#pragma once

#ifdef NOVA_BUILD_DLL
/**
	 * \brief Defines the macro that is used to import/export DLL
	 */
	#define NOVA_API __declspec(dllexport)
#else
	#define NOVA_API __declspec(dllimport)
#endif

// Disable warning for STL using in private data member
#pragma warning(disable:4251)

#ifdef _DEBUG
	#include "Engine/Debug/Logger/LoggerManager.hpp"

	#define LOG_ENGINE_ERROR(X) nova::LoggerManager::get_engine_logger()->log_error(X)
	#define LOG_ENGINE_WARNING(X) nova::LoggerManager::get_engine_logger()->log_warning(X)
	#define LOG_ENGINE_INFORMATION(X) nova::LoggerManager::get_engine_logger()->log_information(X)

	#define LOG_APPLICATION_ERROR(X) nova::LoggerManager::get_application_logger()->log_error(X)
	#define LOG_APPLICATION_WARNING(X) nova::LoggerManager::get_application_logger()->log_warning(X)
	#define LOG_APPLICATION_INFORMATION(X) nova::LoggerManager::get_application_logger()->log_information(X)
#else
	#define LOG_ENGINE_ERROR(X) 
	#define LOG_ENGINE_WARNING(X) 
	#define LOG_ENGINE_INFORMATION(X)

	#define LOG_APPLICATION_ERROR(X) 
	#define LOG_APPLICATION_WARNING(X) 
	#define LOG_APPLICATION_INFORMATION(X)	
#endif


#include <cstddef>
namespace nova
{
	using Int8 = __int8;
	using Int16 = __int16;
	using Int32 = __int32;
	using Int64 = __int64;

	using Float = float;

	using Bool = bool;
}