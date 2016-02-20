#ifndef __LOGSERVICE_H__
#define __LOGSERVICE_H__

#include <mutex>
#include <sstream>
#include <string>

#include "Stream.h"

namespace blackbox {
	namespace log {

		template <typename T>
		class Service {
		public:
			Service();
			~Service();

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
}

#include "Service.cpp"

#endif
