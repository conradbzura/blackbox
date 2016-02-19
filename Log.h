#ifndef __LOG_H__
#define __LOG_H__

#include "Service.h"
#include "Verbosity.h"

namespace blackbox {

#ifndef LOG_STREAM
	static log::Service<log::File> logService;
#endif
#if LOG_STREAM == LOG_FILE
	static log::Service<log::File> logService;
#endif
#if LOG_STREAM == LOG_DATABASE
	static log::Service<log::Database> logService;
#endif
#if LOG_STREAM == LOG_STRING
	static log::Service<log::String> logService;
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

}

#endif
