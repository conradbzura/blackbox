#include "Order.h"
#include "Index.h"

namespace blackbox {

	Order::Order() {
		//noop
	}

	Order::~Order() {
		//noop
	}

	Order::operator Subscript() {
		return Subscript(*this);
	}

	Index Order::toIndex() {
		return Subscript::toIndex(*this);
	}
}