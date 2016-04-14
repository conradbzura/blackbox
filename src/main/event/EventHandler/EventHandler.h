#ifndef __EVENTHANDLER_H__
#define __EVENTHANDLER_H__

#include <typeinfo>

#include "main/context/Mode.h"
#include "main/log/Log.h"
#include "main/pattern/Singleton.h"

#include "main/event/Event/Event.h"

namespace blackbox {
	namespace Events {
	class EventHandler : public Singleton<EventHandler> {
	public:
		EventHandler() = default;
		~EventHandler() = default;

		void handle(ErrorEvent visitee);
		void handle(WarningEvent visitee);
		void handle(BenchmarkEvent visitee);
		void handle(DiagnosticEvent visitee);
		void handle(FaultEvent visitee);
		void handle(DebugEvent visitee);
	};

	#define MODE DEBUG_MODE

	#if MODE >= ALPHA_MODE
	#define ERROR(message) Events::EventHandler::Instance().handle(Events::ErrorEvent(message, __FILE__, __LINE__))
	#else
	#define ERROR(...)
	#endif

	#if MODE >= BETA_MODE
	#define WARNING(message) Events::EventHandler::Instance().handle(Events::WarningEvent(message, __FILE__, __LINE__))
	#else
	#define WARNING(...)
	#endif

	#if MODE >= BENCHMARK_MODE
	#define BENCHMARK(message) Events::EventHandler::Instance().handle(Events::BenchmarkEvent(message, __FILE__, __LINE__))
	#else
	#define BENCHMARK(...)
	#endif

	#if MODE >= DIAGNOSTIC_MODE
	#define DIAGNOSTIC(message) Events::EventHandler::Instance().handle(Events::DiagnosticEvent(message, __FILE__, __LINE__))
	#else
	#define DIAGNOSTIC(...)
	#endif

	#if MODE >= DEBUG_MODE
	#define DEBUG(message) Events::EventHandler::Instance().handle(Events::DebugEvent(message, __FILE__, __LINE__))
	#define FAULT(message) Events::EventHandler::Instance().handle(Events::FaultEvent(message, __FILE__, __LINE__, false))
	#define ASSERT(message, condition) Events::EventHandler::Instance().handle(Events::FaultEvent(message, __FILE__, __LINE__, condition))
	#else
	#define DEBUG(...)
	#define FAULT(...)
	#define ASSERT(...)
	#endif
}
}
#endif

