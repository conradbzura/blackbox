#ifndef __EVENT_H__
#define __EVENT_H__

#include <stdexcept>
#include <string>

#include "context/Mode.h"
#include "log/Log.h"

namespace blackbox {
	class Event {
	public:
		Event() = delete;
		Event(std::string file, int line, std::string message) : file_(file), line_(line), message_(message) {}
		~Event() {}

		int getLine() { return line_; }
		std::string getFile() { return file_; }
		std::string getMessage() { return message_; }

		virtual void handle() = 0;
		virtual std::string getSeverity() = 0;

	protected:
		int line_;
		std::string file_;
		std::string message_;
	};

	class ErrorEvent : public Event {
	public:
		ErrorEvent() = delete;
		ErrorEvent(std::string file, int line, std::string message) : Event(file, line, message) {}
		~ErrorEvent() {}

		void handle() { LOG_SERVICE.log(getSeverity(), file_, line_, message_); throw std::runtime_error(message_); }

		std::string getSeverity() { return "ERROR"; }
	};

	class WarningEvent : public Event {
	public:
		WarningEvent() = delete;
		WarningEvent(std::string file, int line, std::string message) : Event(file, line, message) {}
		~WarningEvent() {}

		void handle() { LOG_SERVICE.log(getSeverity(), file_, line_, message_); }
		std::string getSeverity() { return "WARNING"; }
	};

	class DiagnosticEvent : public Event {
	public:
		DiagnosticEvent() = delete;
		DiagnosticEvent(std::string file, int line, std::string message) : Event(file, line, message) {}
		~DiagnosticEvent() {}

		void handle() { LOG_SERVICE.log(getSeverity(), file_, line_, message_); }
		std::string getSeverity() { return "DIAGNOSTIC"; }
	};

	class DebugEvent : public Event {
	public:
		DebugEvent() = delete;
		DebugEvent(std::string file, int line, std::string message) : Event(file, line, message) {}
		DebugEvent(std::string file, int line, std::string message, bool condition) : Event(file, line, message), condition_(condition) {}
		~DebugEvent() {}

		void handle() { if (condition_ < 1) LOG_SERVICE.log(getSeverity(), file_, line_, message_); if (!condition_) throw std::logic_error(message_); }

		std::string getSeverity() { return "DEBUG"; }

	private:
		int condition_ = -1;
	};

	#if MODE >= Mode::Debug
	#define DEBUG(message) DebugEvent(__FILE__, __LINE__, message).handle()//EventService::Instance().handle(__FILE__, __LINE__, DebugEvent(message))
	#define ASSERT(message, condition) DebugEvent(__FILE__, __LINE__, message, condition).handle()//EventService::Instance().handle(__FILE__, __LINE__, DebugEvent(message), condition)
	#else
	#define DEBUG(...)
	#define ASSERT(...)
	#endif
	#if MODE >= Mode::Diagnostic
	#define INFO(message) DiagnosticEvent(__FILE__, __LINE__, message).handle()//EventService::Instance().handle(__FILE__, __LINE__, DiagnosticEvent(message))
	#else
	#define INFO(...)
	#endif
	#if MODE >= Mode::Release
	#define WARNING(message) WarningEvent(__FILE__, __LINE__, message).handle()//EventService::Instance().handle__FILE__, __LINE__, (WarningEvent(message))
	#else
	#define WARNING(...)
	#endif
	#if MODE >= Mode::Release
	#define ERROR(message) ErrorEvent(__FILE__, __LINE__, message).handle()//EventService::Instance().handle(__FILE__, __LINE__, ErrorEvent(message))
	#else
	#define ERROR(...)
	#endif
}

#endif
