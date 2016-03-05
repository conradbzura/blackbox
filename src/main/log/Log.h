#ifndef __LOG_H__
#define __LOG_H__

#include "LogService.h"
#include "LogVerbosity.h"

namespace blackbox {
	#ifndef LOG_STREAM
	#define LOG_SERVICE LogService<LogStream::File>::Instance()
	#endif
	#if LOG_STREAM == LOG_FILE
	#define LOG_SERVICE LogService<LogStream::File>::Instance()
	#endif
	#if LOG_STREAM == LOG_DATABASE
	#define LOG_SERVICE LogService<LogStream::Database>::Instance()
	#endif
	#if LOG_STREAM == LOG_STRING
	#define LOG_SERVICE LogService<LogStream::String>::Instance()
	#endif

	#if LOG_VERBOSITY > 3
	#define DEBUG(message) LOG_SERVICE.log<LogVerbosity::Debug>(__FILE__, __LINE__, message)
	#else
	#define DEBUG(...)
	#endif
	#if LOG_VERBOSITY > 2
	#define INFO(message) LOG_SERVICE.log<LogVerbosity::Info>(__FILE__, __LINE__, message)
	#else
	#define INFO(...)
	#endif
	#if LOG_VERBOSITY > 1
	#define WARNING(message) LOG_SERVICE.log<LogVerbosity::Warning>(__FILE__, __LINE__, message)
	#else
	#define WARNING(...)
	#endif
	#if LOG_VERBOSITY > 0
	#define ERROR(message) LOG_SERVICE.log<LogVerbosity::Error>(__FILE__, __LINE__, message)
	#else
	#define ERROR(...)
	#endif
}

#endif
