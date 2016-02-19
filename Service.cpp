#ifdef __LOGSERVICE_H__

namespace blackbox {
	namespace log {

		template <typename T>
		const char* Service<T>::DELIM = ",";

		template <typename T>
		Service<T>::Service() {
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
		Service<T>::~Service() {
			if (stream_) {
				stream_->close();
				delete stream_;
			}
		}

		template <typename T>
		template <typename V>
		void Service<T>::log(std::string file, int line, std::string message) {
			mutex_.lock();
			stream_->write(getLogEntry(V(), file, line, message));
		}

		template <typename T>
		std::string Service<T>::getTime() {
			std::string timestamp;
			time_t millis;
			time(&millis);
			timestamp = ctime(&millis);
			return timestamp.substr(0, timestamp.size() - 1);
		}

		template <typename T>
		std::string Service<T>::getHeader() {
			std::stringstream logHeader;
			logHeader << "SEVERITY" << DELIM << "TIMESTAMP" << DELIM << "FILE" << DELIM << "LINE" << DELIM << "MESSAGE";
			return logHeader.str();
		}

		template <typename T>
		std::string Service<T>::getLogEntry(std::string severity, std::string file, int line, std::string message) {
			std::stringstream logEntry;
			logEntry << severity << DELIM << getTime() << DELIM << file << DELIM << line << DELIM << message;
			return logEntry.str();
		}
	}
}

#endif
