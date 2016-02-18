#ifndef __LOG_H__
#define __LOG_H__

#include "LogService.h"

namespace log {

#ifndef LOG_STREAM
	static LogService<File> logService;
#endif
#if LOG_STREAM == LOG_FILE
	static LogService<File> logService;
#endif
#if LOG_STREAM == LOG_DATABASE
	static LogService<Database> logService;
#endif
#if LOG_STREAM == LOG_STRING
	static LogService<String> logService;
#endif

#if LOG_VERBOSITY > 3
#define DEBUG logService.log<Debug>
#else
#define DEBUG(...)
#endif
#if LOG_VERBOSITY > 2
#define INFO logService.log<Info>
#else
#define INFO(...)
#endif
#if LOG_VERBOSITY > 1
#define WARNING logService.log<Warning>
#else
#define WARNING(...)
#endif
#if LOG_VERBOSITY > 0
#define ERROR logService.log<Error>
#else
#define ERROR(...)
#endif

}

#endif
