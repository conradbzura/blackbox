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

		void log(std::string type, std::string message, std::string file, int line);

	private:
		std::string getTime();
		std::string buildHeader();
		std::string buildEntry(int index, std::string type, std::string message, std::string file, int line);

		T* stream_;
		int index_ = 1;
		std::mutex mutex_;
		static const char* DELIM;
	};
}

#include "LogService.cpp"

#endif
