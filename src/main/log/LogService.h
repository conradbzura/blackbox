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

		void log(std::string severity, std::string file, int line, std::string message);

	private:
		std::string getTime();
		std::string buildHeader();
		std::string buildEntry(std::string severity, std::string file, int line, std::string message);

		T* stream_;
		std::mutex mutex_;
		static const char* DELIM;
	};
}

#include "LogService.cpp"

#endif
