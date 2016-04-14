#ifndef __IMPLEMENTATIONWARNING_H__
#define __IMPLEMENTATIONWARNING_H__

#include <string>

#include "EventMessage.h"

namespace blackbox {
	namespace Events {
	class ImplementationWarning : public EventMessage {
	public:
		ImplementationWarning() = delete;
		~ImplementationWarning() = default;
		ImplementationWarning(std::string functionName, std::string className);

	private:
		std::string neuter(std::string string);
		std::string trimFunctionName(std::string functionName);
		std::string format(std::string functionName, std::string className);

		static const std::string STRING_TO_NEUTER_;
		static const std::string START_OF_FUNCTION_SIGNATURE_;
	};
}
}
#define __IMPLEMENTATION_WARNING__ blackbox::event::ImplementationWarning(__FUNCSIG__, typeid(*this).name())

#endif
