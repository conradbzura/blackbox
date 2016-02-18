#ifndef __LOG_H__
#define __LOG_H__

#include "LogService.h"

#ifndef LOG_STREAM
	static log::LogService<log::File> logService;
#endif
#if LOG_STREAM == LOG_FILE
	static log::LogService<log::File> logService;
#endif
#if LOG_STREAM == LOG_DATABASE
	static log::LogService<log::Database> logService;
#endif
#if LOG_STREAM == LOG_STRING
	static log::LogService<log::String> logService;
#endif

#if LOG_VERBOSITY > 3
#define DEBUG logService.log<log::Debug>
#else
#define DEBUG(...)
#endif
#if LOG_VERBOSITY > 2
#define INFO logService.log<log::Info>
#else
#define INFO(...)
#endif
#if LOG_VERBOSITY > 1
#define WARNING logService.log<log::Warning>
#else
#define WARNING(...)
#endif
#if LOG_VERBOSITY > 0
#define ERROR logService.log<log::Error>
#else
#define ERROR(...)
#endif

#endif
