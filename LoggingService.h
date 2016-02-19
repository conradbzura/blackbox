#ifndef __LOGGINGSERVICE_H__
#define __LOGGINGSERVICE_H__

#include <mutex>
#include <sstream>
#include <string>

#include "Stream.h"

namespace logger {

template <typename T>
class LoggingService {
public:
	LoggingService();
	~LoggingService();

	//todo: add timestamp
	template <typename V>
	void log(std::string file, int line, std::string message);

private:
	std::string getTime();
	std::string getHeader();
	std::string getLogEntry(std::string verbosity, std::string file, int line, std::string message);

	T* stream_;
	std::mutex mutex_;
	static const char DELIM = ',';
};

} //namespace: logger

#include "LoggingService.cpp"

#endif
