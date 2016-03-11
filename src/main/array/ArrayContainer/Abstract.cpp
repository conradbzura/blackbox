#ifdef __ABSTRACTARRAYCONTAINER_H__

#include <typeinfo>

#include "event/EventMessage/ImplementationWarning.h"
#include "event/EventHandler/EventHandler.h"

namespace blackbox {

	template <typename T>
	AbstractArrayContainer<T>::AbstractArrayContainer(Subscript order) : order_(order) {
		//noop
	}

	template <typename T>
	AbstractArrayContainer<T>::~AbstractArrayContainer() {
		//noop
	}

	template <typename T>
	std::auto_ptr<AbstractArrayContainer<T>> AbstractArrayContainer<T>::clone() {
		WARNING(__IMPLEMENTATION_WARNING__);
		std::auto_ptr<AbstractArrayContainer<T>> replica = this->create();
		Range range(order_);
		Range::Iterator n = range.getIterator(range.getFloor());
		for (Range::Iterator i = range.getIterator(range.getFloor()); i <= range.getCeiling(); ++i) {
			*replica->at(n) = *this->at(i);
			++n;
		}
		return replica;
	}

	template <typename T>
	std::auto_ptr<AbstractArrayContainer<T>> AbstractArrayContainer<T>::create() {
		return this->create(order_);
	}

	template <typename T>
	auto AbstractArrayContainer<T>::at(Subscript subscript) -> std::shared_ptr<T>& {
		return this->at(subscript.toIndex(order_));
	}

	template <typename T>
	auto AbstractArrayContainer<T>::at(Subscript floor, Subscript ceiling) -> std::auto_ptr<AbstractArrayContainer<T>> {
		return this->at(Range(floor, ceiling));
	}

	template <typename T>
	auto AbstractArrayContainer<T>::at(Range range) -> std::auto_ptr<AbstractArrayContainer<T>> {
		WARNING(__IMPLEMENTATION_WARNING__);
		std::auto_ptr<AbstractArrayContainer<T>> replica = this->create(range.getOrder());
		Range newRange(range.getOrder());
		Range::Iterator n = newRange.getIterator(range.getFloor());
		for (Range::Iterator i = range.getIterator(range.getFloor()); i <= range.getCeiling(); ++i) {
			replica->at(n) = this->at(i);
			++n;
		}
		return replica;
	}

	template <typename T>
	Integer AbstractArrayContainer<T>::getSize() {
		return order_.toIndex();
	}

	template <typename T>
	Subscript AbstractArrayContainer<T>::getOrder() {
		return order_;
	}
}


#endif
