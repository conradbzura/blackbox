#ifdef __ABSTRACTARRAYCONTAINER_H__

#include <typeinfo>

#include "event/ImplementationWarning.h"
#include "log/Log.h"

namespace blackbox {

	template <typename T>
	ArrayContainer::Abstract<T>::Abstract(Subscript order) : order_(order) {
		//noop
	}

	template <typename T>
	ArrayContainer::Abstract<T>::~Abstract() {
		//noop
	}

	template <typename T>
	void ArrayContainer::Abstract<T>::duplicateTo(Abstract<T>& replica, Range range) {
		WARNING(__IMPLEMENTATION_WARNING__);
		this->translateTo(replica, range);
	}

	template <typename T>
	void ArrayContainer::Abstract<T>::translateTo(Abstract<T>& replica, Range range) {
		WARNING(__IMPLEMENTATION_WARNING__);
		Range newRange(range.getOrder());
		Range::Iterator n = newRange.getIterator(newRange.getFloor());
		for (Range::Iterator i = range.getIterator(range.getFloor()); i <= range.getCeiling(); ++i) {
			replica.at(n) = this->at(i);
			++n;
		}
	}

	template <typename T>
	auto ArrayContainer::Abstract<T>::at(Subscript subscript) -> std::shared_ptr<T>& {
		return this->at(subscript.toIndex(order_));
	}

	template <typename T>
	auto ArrayContainer::Abstract<T>::at(Subscript floor, Subscript ceiling) -> std::auto_ptr<Abstract<T>> {
		return this->at(Range(floor, ceiling));
	}

	template <typename T>
	auto ArrayContainer::Abstract<T>::at(Range range) -> std::auto_ptr<Abstract<T>> {
		WARNING(__IMPLEMENTATION_WARNING__);
		std::auto_ptr<Abstract<T>> replica = this->create(range.getOrder());
		this->duplicateTo(*replica, range);
		return replica;
	}

	template <typename T>
	Integer ArrayContainer::Abstract<T>::getSize() {
		return order_.toIndex();
	}

	template <typename T>
	Subscript ArrayContainer::Abstract<T>::getOrder() {
		return order_;
	}

	template <typename T>
	void ArrayContainer::Abstract<T>::duplicateTo(Abstract<T>& replica) {
		this->duplicateTo(replica, Range(order_));
	}

	template <typename T>
	void ArrayContainer::Abstract<T>::translateTo(Abstract<T>& replica) {
		this->translateTo(replica, Range(order_));
	}
}


#endif
