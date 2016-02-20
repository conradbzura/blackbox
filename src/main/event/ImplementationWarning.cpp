#include "ImplementationWarning.h"

namespace blackbox {
	namespace event {

		const std::string ImplementationWarning::START_OF_FUNCTION_SIGNATURE_ = "__thiscall";

		ImplementationWarning::ImplementationWarning(std::string functionName, std::string className) : message_(format(functionName, className)) {
			//noop
		}

		ImplementationWarning::~ImplementationWarning() {
			//noop
		}

		ImplementationWarning::operator std::string() {
			return message_;
		}

		std::string ImplementationWarning::format(std::string functionName, std::string className) {
			return "No override found for method [" + trim(functionName) + "] in class [" + className + "] - executing default implementation.";
		}

		std::string ImplementationWarning::trim(std::string functionName) {
			return functionName.substr(functionName.find(START_OF_FUNCTION_SIGNATURE_) + START_OF_FUNCTION_SIGNATURE_.size() + 1, functionName.size());
		}
	}
}
