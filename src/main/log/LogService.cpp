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
		stream_->write(buildHeader());
	}

	template <typename T>
	LogService<T>::~LogService() {
		if (stream_) {
			stream_->close();
			delete stream_;
		}
	}

	template <typename T>
	void LogService<T>::log(std::string type, std::string message, std::string file, int line) {
		mutex_.lock();
		stream_->write(buildEntry(index_++, type, message, file, line));
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
		std::stringstream header;
		header << "INDEX" << DELIM << "TIMESTAMP" << DELIM << "TYPE" << DELIM << "MESSAGE" << DELIM << "FILE" << DELIM << "LINE";
		return header.str();
	}

	template <typename T>
	std::string LogService<T>::buildEntry(int index, std::string type, std::string message, std::string file, int line) {
		std::stringstream entry;
		entry << index << DELIM << getTime() << DELIM << type << DELIM << "\"" << message << "\"" << DELIM << file << DELIM << line;
		return entry.str();
	}
}

#endif
