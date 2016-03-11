#ifndef __EVENT_H__
#define __EVENT_H__

#include <string>
#include <stdexcept>

#include "log/Log.h"
#include "context/Mode.h"
#include "pattern/Visitable.h"

namespace blackbox {
	class Event {
	public:
		Event() = delete;
		~Event() = default;
		Event(const Event&) = default;
		Event(std::string type, std::string message, std::string file, int line) : type_(type), message_(message), file_(file), line_(line) {}

		int getLine() { return line_; }
		std::string getFile() { return file_; }
		std::string getType() { return type_; }
		std::string getMessage() { return message_; }

	protected:
		int line_;
		std::string type_;
		std::string file_;
		std::string message_;
	};

	class ErrorEvent : public Event {
	public:
		ErrorEvent(std::string message, std::string file, int line) : Event("ERROR", message, file, line) {}
	};

	class WarningEvent : public Event {
	public:
		WarningEvent(std::string message, std::string file, int line) : Event("WARNING", message, file, line) {}
	};

	class BenchmarkEvent : public Event {
	public:
		BenchmarkEvent(std::string message, std::string file, int line) : Event("BENCHMARK", message, file, line) {}
	};

	class DiagnosticEvent : public Event {
	public:
		DiagnosticEvent(std::string message, std::string file, int line) : Event("DIAGNOSTIC", message, file, line) {}
	};

	class FaultEvent : public Event {
	public:
		FaultEvent(std::string message, std::string file, int line, bool condition) : Event("FAULT", message, file, line), condition_(condition) {}

		bool getCondition() { return condition_; }

	private:
		int condition_;
	};

	class DebugEvent : public Event {
	public:
		DebugEvent(std::string message, std::string file, int line) : Event("DEBUG", message, file, line) {}
	};
}

#endif
