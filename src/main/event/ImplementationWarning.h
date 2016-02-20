#ifndef __IMPLEMENTATIONWARNING_H__
#define __IMPLEMENTATIONWARNING_H__

#include <string>

namespace blackbox {
	namespace event {

		class ImplementationWarning {
		public:
			ImplementationWarning() = delete;
			ImplementationWarning(std::string function, std::string className);
			~ImplementationWarning();

			operator std::string();

		private:
			std::string format(std::string function, std::string className);
			std::string trim(std::string function);

			std::string message_;
			static const std::string START_OF_FUNCTION_SIGNATURE_;
		};
	}
}

#endif
