#ifndef __EVENTMESSAGE_H__
#define __EVENTMESSAGE_H__

#include <string>

namespace blackbox {
	namespace Events {
	class EventMessage {
	public:
		EventMessage(std::string message) : message_(message) {}

		virtual operator std::string() { return message_; }

	protected:
		std::string message_;
	};
}
}
#endif

