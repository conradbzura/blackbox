#ifndef __EVENTHANDLER_H__
#define __EVENTHANDLER_H__

#include <typeinfo>

#include "context/Mode.h"
#include "log/Log.h"
#include "pattern/Singleton.h"

#include "event/Event/Event.h"

namespace blackbox {
	class EventHandler : public Singleton<EventHandler> {
	public:
		EventHandler() = default;
		~EventHandler() = default;

		void handle(ErrorEvent& visitee);
		void handle(WarningEvent& visitee);
		void handle(BenchmarkEvent& visitee);
		void handle(DiagnosticEvent& visitee);
		void handle(FaultEvent& visitee);
		void handle(DebugEvent& visitee);
	};

	#define MODE ALPHA_MODE

	#if MODE >= ALPHA_MODE
	#define ERROR(message) EventHandler::Instance().handle(ErrorEvent(message, __FILE__, __LINE__))
	#else
	#define ERROR(...)
	#endif

	#if MODE >= BETA_MODE
	#define WARNING(message) EventHandler::Instance().handle(WarningEvent(message, __FILE__, __LINE__))
	#else
	#define WARNING(...)
	#endif

	#if MODE >= BENCHMARK_MODE
	#define BENCHMARK(message) EventHandler::Instance().handle(BenchmarkEvent(message, __FILE__, __LINE__))
	#else
	#define BENCHMARK(...)
	#endif

	#if MODE >= DIAGNOSTIC_MODE
	#define DIAGNOSTIC(message) EventHandler::Instance().handle(DiagnosticEvent(message, __FILE__, __LINE__))
	#else
	#define DIAGNOSTIC(...)
	#endif

	#if MODE >= DEBUG_MODE
	#define DEBUG(message) EventHandler::Instance().handle(DebugEvent(message, __FILE__, __LINE__))
	#define FAULT(message) EventHandler::Instance().handle(FaultEvent(message, __FILE__, __LINE__, false))
	#define ASSERT(message, condition) EventHandler::Instance().handle(FaultEvent(message, __FILE__, __LINE__, condition))
	#else
	#define DEBUG(...)
	#define FAULT(...)
	#define ASSERT(...)
	#endif
}

#endif

