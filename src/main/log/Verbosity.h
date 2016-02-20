#ifndef __VERBOSITY_H__
#define __VERBOSITY_H__

#include <string>

namespace blackbox {
	namespace log {
		//todo: split the implementation classes out into separate files

		class Verbosity {
		protected:
			Verbosity() {}
		};

		class Error : public Verbosity {
		public:
			operator std::string() {
				return "ERROR";
			}
		};

		class Warning : public Verbosity {
		public:
			operator std::string() {
				return "WARNING";
			}
		};

		class Info : public Verbosity {
		public:
			operator std::string() {
				return "INFO";
			}
		};

		class Debug : public Verbosity {
		public:
			operator std::string() {
				return "DEBUG";
			}
		};

	}
}

#endif
