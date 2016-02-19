#ifndef __LOG_H__
#define __LOG_H__

#include "LoggingService.h"
#include "Verbosity.h"
//todo: change "logger" namespace back to "log" after nesting inside new "blackbox" namespace

#ifndef LOG_STREAM
	static logger::LoggingService<logger::File> loggingService;
#endif
#if LOG_STREAM == LOG_FILE
	static logger::LogService<logger::File> loggingService;
#endif
#if LOG_STREAM == LOG_DATABASE
	static logger::LogService<logger::Database> loggingService;
#endif
#if LOG_STREAM == LOG_STRING
	static logger::LogService<logger::String> loggingService;
#endif

#if LOG_VERBOSITY > 3
#define DEBUG loggingService.log<logger::Debug>
#else
#define DEBUG(...)
#endif
#if LOG_VERBOSITY > 2
#define INFO loggingService.log<logger::Info>
#else
#define INFO(...)
#endif
#if LOG_VERBOSITY > 1
#define WARNING loggingService.log<logger::Warning>
#else
#define WARNING(...)
#endif
#if LOG_VERBOSITY > 0
#define ERROR loggingService.log<logger::Error>
#else
#define ERROR(...)
#endif

#endif
