#ifndef __LOGSERVICE_H__
#define __LOGSERVICE_H__

#include <mutex>
#include <sstream>
#include <string>

#include "LogStream.h"
#include "pattern/Singleton.h"

namespace blackbox {
	template <typename T>
	class LogService : public Singleton<LogService<T>> {
	public:
		LogService();
		~LogService();

		template <typename V>
		void log(std::string file, int line, std::string message);

	private:
		std::string getTime();
		std::string getLogHeader();
		std::string getLogEntry(std::string verbosity, std::string file, int line, std::string message);

		T* stream_;
		std::mutex mutex_;
		static const char* DELIM;
	};
}

#include "LogService.cpp"

#endif
