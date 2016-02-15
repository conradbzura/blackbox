#ifdef __ABSTRACTARRAYCONTAINER_H__

//#include "AbstractArrayContainer.h"
template <typename T>
AbstractArrayContainer<T>::AbstractArrayContainer() {
	//noop
}

template <typename T>
AbstractArrayContainer<T>::AbstractArrayContainer(Subscript order) : order_(order) {
	//noop
}

template <typename T>
AbstractArrayContainer<T>::~AbstractArrayContainer() {
	//noop
}

template <typename T>
void AbstractArrayContainer<T>::duplicateTo(AbstractArrayContainer<T>& replica, Range range) {
	//todo: default implementation warning
	this->translateTo(replica, range);
}

template <typename T>
void AbstractArrayContainer<T>::translateTo(AbstractArrayContainer<T>& replica, Range range) {
	//todo: default implementation warning
	Range newRange(range.getOrder());
	Range::Iterator n = newRange.getIterator(newRange.getFloor());
	for (Range::Iterator i = range.getIterator(range.getFloor()); i <= range.getCeiling(); ++i) {
		replica.at(n) = this->at(i);
		++n;
	}
}

template <typename T>
auto AbstractArrayContainer<T>::at(Subscript subscript)-> std::shared_ptr<T>& {
	return this->at(subscript.toIndex(order_));
}

template <typename T>
auto AbstractArrayContainer<T>::at(Subscript floor, Subscript ceiling)-> std::auto_ptr<AbstractArrayContainer<T>> {
	return this->at(Range(floor, ceiling));
}

template <typename T>
auto AbstractArrayContainer<T>::at(Range range)-> std::auto_ptr<AbstractArrayContainer<T>> {
	//todo: default implementation warning
	std::auto_ptr<AbstractArrayContainer<T>> replica = this->create(range.getOrder());
	this->duplicateTo(*replica, range);
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

template <typename T>
void AbstractArrayContainer<T>::duplicateTo(AbstractArrayContainer<T>& replica) {
	this->duplicateTo(replica, Range(order_));
}

template <typename T>
void AbstractArrayContainer<T>::translateTo(AbstractArrayContainer<T>& replica) {
	this->translateTo(replica, Range(order_));
}

#endif
