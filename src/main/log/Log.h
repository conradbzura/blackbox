#ifndef __LOG_H__
#define __LOG_H__

#include "LogService.h"

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
}

#endif
