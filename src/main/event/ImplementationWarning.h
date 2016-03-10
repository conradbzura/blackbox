#ifndef __IMPLEMENTATIONWARNING_H__
#define __IMPLEMENTATIONWARNING_H__

#include <string>

#include "EventMessage.h"

namespace blackbox {
	class ImplementationWarning : public EventMessage {
	public:
		ImplementationWarning() = delete;
		ImplementationWarning(std::string functionName, std::string className);
		~ImplementationWarning();

	private:
		std::string format(std::string functionName, std::string className);
		std::string neuter(std::string string);
		std::string trimFunctionName(std::string functionName);

		static const std::string START_OF_FUNCTION_SIGNATURE_;
		static const std::string STRING_TO_NEUTER_;
	};
}

#define __IMPLEMENTATION_WARNING__ blackbox::ImplementationWarning(__FUNCSIG__, typeid(*this).name())

#endif
