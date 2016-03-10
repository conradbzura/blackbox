#ifdef __LOGSERVICE_H__

namespace blackbox {

	template <typename T>
	const char* LogService<T>::DELIM = ",";

	template <typename T>
	LogService<T>::LogService() {
		stream_ = new T();
		if (!stream_) {
			char errorMessage[256];
			snprintf(errorMessage, 256, "ERROR<%s:%d>: Could not instantiate %s!", __FILE__, __LINE__ - 3, typeid(T).name());
			throw (std::runtime_error(errorMessage));
		}
		stream_->open();
		stream_->write(getLogHeader());
	}

	template <typename T>
	LogService<T>::~LogService() {
		if (stream_) {
			stream_->close();
			delete stream_;
		}
	}

	template <typename T>
	void LogService<T>::log(std::string severity, std::string file, int line, std::string message) {
		mutex_.lock();
		stream_->write(buildEntry(severity, file, line, message));
		mutex_.unlock();
	}

	template <typename T>
	std::string LogService<T>::getTime() {
		std::string timestamp;
		time_t millis;
		time(&millis);
		timestamp = ctime(&millis);
		return timestamp.substr(0, timestamp.size() - 1);
	}

	template <typename T>
	std::string LogService<T>::buildHeader() {
		std::stringstream logHeader;
		header << "SEVERITY" << DELIM << "TIMESTAMP" << DELIM << "FILE" << DELIM << "LINE" << DELIM << "MESSAGE";
		return header.str();
	}

	template <typename T>
	std::string LogService<T>::buildEntry(std::string severity, std::string file, int line, std::string message) {
		std::stringstream logEntry;
		entry << severity << DELIM << getTime() << DELIM << file << DELIM << line << DELIM << "\"" << message << "\"";
		return entry.str();
	}
}

#endif
