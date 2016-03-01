#ifndef __LOGVERBOSITY_H__
#define __LOGVERBOSITY_H__

#include <string>

namespace blackbox {
		//TODO split the implementation classes out into separate files

		class LogVerbosity {
		public:
			class Debug;
			class Error;
			class Info;
			class Warning;
		protected:
			LogVerbosity() {}
		};

		class LogVerbosity::Debug : public LogVerbosity {
		public:
			operator std::string() {
				return "DEBUG";
			}
		};

		class LogVerbosity::Error : public LogVerbosity {
		public:
			operator std::string() {
				return "ERROR";
			}
		};

		class LogVerbosity::Info : public LogVerbosity {
		public:
			operator std::string() {
				return "INFO";
			}
		};

		class LogVerbosity::Warning : public LogVerbosity {
		public:
			operator std::string() {
				return "WARNING";
			}
		};
}

#endif
