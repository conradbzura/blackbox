#ifndef __LOGSERVICE_H__
#define __LOGSERVICE_H__

#include <fstream>
#include <string>

#include "LogStream.h"

template <typename Policy>
class LogService {
public:
	LogService(const std::string& name);
	~LogService();

	template <Verbosity V, typename... Args>
	void print(Args... args);

private:
	std::string getTime();
	std::string getHeader();

	unsigned line_;
	std::mutex mutex_;
	LogStream* logStream_;
	std::stringstream stringStream_;

};

static LogService<LogStream> log("execution.log");

#ifdef LOGGING_LEVEL_1
#define DEBUG log.print<Verbosity::Debug>
#define INFO log.print<Verbosity::Info>
#define WARNING log.print<Verbosity::Warning>
#define ERROR log.print<Verbosity::Error>
#else
#define DEBUG(...) 
#define INFO(...)
#define WARNING(...)
#define ERROR(...)
#endif

#ifdef LOGGING_LEVEL_2
#define ELOG log_inst.print< logging::severity_type::debug >
#define ELOG_ERR log_inst.print< logging::severity_type::error >
#define ELOG_WARN log_inst.print< logging::severity_type::warning >
#else
#define ELOG(...) 
#define ELOG_ERR(...)
#define ELOG_WARN(...)
#endif

#endif
