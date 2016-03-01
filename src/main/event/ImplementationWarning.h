#ifndef __IMPLEMENTATIONWARNING_H__
#define __IMPLEMENTATIONWARNING_H__

#include <string>

#include "Event.h"

namespace blackbox {
	namespace event {

		class ImplementationWarning : public Event {
		public:
			ImplementationWarning() = delete;
			ImplementationWarning(std::string function, std::string className);
			~ImplementationWarning();

			operator std::string();

		private:
			std::string format(std::string function, std::string className);
			std::string neuter(std::string string);
			std::string trimFunctionName(std::string function);

			std::string message_;
			static const std::string START_OF_FUNCTION_SIGNATURE_;
			static const std::string STRING_TO_NEUTER_;
		};
	}
}

#define __IMPLEMENTATION_WARNING__ blackbox::event::ImplementationWarning(__FUNCSIG__, typeid(*this).name())

#endif
