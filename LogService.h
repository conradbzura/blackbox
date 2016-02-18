#ifndef __LOGSERVICE_H__
#define __LOGSERVICE_H__

#include <string>

#include "Stream.h"

namespace log {

template <typename T>
class LogService {
public:
	LogService();
	~LogService();

	template <Verbosity V>
	void log(std::string file, std::string line, std::string message);

private:
	std::string getTime();
	std::string getHeader();

	T* stream_;
	unsigned line_;
	std::mutex mutex_;

};

} //namespace: log

#endif
