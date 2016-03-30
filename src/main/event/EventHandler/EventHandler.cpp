#include "EventHandler.h"

namespace blackbox {
	
	void EventHandler::handle(ErrorEvent event) {
		LOG_SERVICE.log(event.getType(), event.getMessage(), event.getFile(), event.getLine());
		throw std::runtime_error(event.getMessage());
	}

	void EventHandler::handle(WarningEvent event) {
		LOG_SERVICE.log(event.getType(), event.getMessage(), event.getFile(), event.getLine());
	}

	void EventHandler::handle(BenchmarkEvent event) {
		LOG_SERVICE.log(event.getType(), event.getMessage(), event.getFile(), event.getLine());
	}

	void EventHandler::handle(DiagnosticEvent event) {
		LOG_SERVICE.log(event.getType(), event.getMessage(), event.getFile(), event.getLine());
	}

	void EventHandler::handle(FaultEvent event) {
		if (!event.getCondition()) {
			LOG_SERVICE.log(event.getType(), event.getMessage(), event.getFile(), event.getLine());
			throw std::logic_error(event.getMessage());
		}
	}

	void EventHandler::handle(DebugEvent event) {
		LOG_SERVICE.log(event.getType(), event.getMessage(), event.getFile(), event.getLine());
	}

}
