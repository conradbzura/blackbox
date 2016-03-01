#include "ImplementationWarning.h"

namespace blackbox {
	namespace event {

		const std::string ImplementationWarning::START_OF_FUNCTION_SIGNATURE_ = "__thiscall";
		const std::string ImplementationWarning::STRING_TO_NEUTER_ = "class ";

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
			return "No override found for method [" + neuter(trimFunctionName(functionName)) + "] in class [" + neuter(className) + "] - executing default implementation.";
		}

		std::string ImplementationWarning::neuter(std::string string) {
			auto position = string.find(STRING_TO_NEUTER_);
			while (position != -1) {
				string.erase(position, STRING_TO_NEUTER_.size());
				position = string.find(STRING_TO_NEUTER_);
			}
			return string;
		}

		std::string ImplementationWarning::trimFunctionName(std::string functionName) {
			return functionName.substr(functionName.find(START_OF_FUNCTION_SIGNATURE_) + START_OF_FUNCTION_SIGNATURE_.size() + 1, functionName.size());
		}
	}
}
