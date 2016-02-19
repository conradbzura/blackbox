#ifdef __LOGGINGSERVICE_H__

namespace logger {

template <typename T>
LoggingService<T>::LoggingService() {
	stream_ = new T();
	if (!stream_) {
		char errorMessage[256];
		snprintf(errorMessage, 256, "ERROR<%s:%d>: Could not instantiate Stream!", __FILE__, __LINE__ - 3);
		throw (std::runtime_error(errorMessage));
	}
	stream_->open();
	stream_->write(getHeader());
}

template <typename T>
LoggingService<T>::~LoggingService() {
	if (stream_) {
		stream_->close();
		delete stream_;
	}
}

template <typename T>
template <typename V>
void LoggingService<T>::log(std::string file, int line, std::string message) {
	mutex_.lock();
	stream_->write(getLogEntry(V(), file, line, message));
}

template <typename T>
std::string LoggingService<T>::getTime() {
	std::string timestamp;
	time_t millis;
	time(&millis);
	timestamp = ctime(&millis);
	return timestamp.substr(0, timestamp.size() - 1);
}

template <typename T>
std::string LoggingService<T>::getHeader() {
	std::stringstream logHeader;
	logHeader << "SEVERITY" << DELIM << "TIMESTAMP" << DELIM << "FILE" << DELIM << "LINE" << DELIM << "MESSAGE";
	return logHeader.str();
}
	
template <typename T>
std::string LoggingService<T>::getLogEntry(std::string severity, std::string file, int line, std::string message) {
	std::stringstream logEntry;
	logEntry << severity << DELIM << getTime() << DELIM << file << DELIM << line << DELIM << message;
	return logEntry.str();
}

} //namespace: logger

#endif
