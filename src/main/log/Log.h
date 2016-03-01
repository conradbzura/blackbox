#ifndef __LOG_H__
#define __LOG_H__

#include "LogService.h"
#include "LogVerbosity.h"

namespace blackbox {
	
	//TODO wrap the static log service in a singleton class
	#ifndef LOG_STREAM //DEFAULT
	static LogService<LogStream::File> logService;
	#endif
	#if LOG_STREAM == LOG_FILE
	static LogService<LogStream::File> logService;
	#endif
	#if LOG_STREAM == LOG_DATABASE
	static LogService<LogStream::Database> logService;
	#endif
	#if LOG_STREAM == LOG_STRING
	static LogService<LogStream::String> logService;
	#endif

	#if LOG_VERBOSITY > 3
	#define DEBUG(message) logService.log<LogVerbosity::Debug>(__FILE__, __LINE__, message)
	#else
	#define DEBUG(...)
	#endif
	#if LOG_VERBOSITY > 2
	#define INFO(message) logService.log<LogVerbosity::Info>(__FILE__, __LINE__, message)
	#else
	#define INFO(...)
	#endif
	#if LOG_VERBOSITY > 1
	#define WARNING(message) logService.log<LogVerbosity::Warning>(__FILE__, __LINE__, message)
	#else
	#define WARNING(...)
	#endif
	#if LOG_VERBOSITY > 0
	#define ERROR(message) logService.log<LogVerbosity::Error>(__FILE__, __LINE__, message)
	#else
	#define ERROR(...)
	#endif

}

#endif
