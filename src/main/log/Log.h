#ifndef __LOG_H__
#define __LOG_H__

#include "LogService.h"

namespace blackbox {
	namespace Log {
	#ifndef LOG_STREAM
	#define LOG_SERVICE Log::LogService<Log::LogStream::File>::Instance()
	#endif
	#if LOG_STREAM == LOG_FILE
	#define LOG_SERVICE Log::LogService<Log::LogStream::File>::Instance()
	#endif
	#if LOG_STREAM == LOG_DATABASE
	#define LOG_SERVICE Log::LogService<Log::LogStream::Database>::Instance()
	#endif
	#if LOG_STREAM == LOG_STRING
	#define LOG_SERVICE Log::LogService<Log::LogStream::String>::Instance()
	#endif
}
}
#endif
