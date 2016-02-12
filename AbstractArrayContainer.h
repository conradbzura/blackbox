#ifndef __ABSTRACTARRAYCONTAINER_H__
#define __ABSTRACTARRAYCONTAINER_H__

#include <memory>

#include "Cloneable.h"
#include "Index.h"
#include "Range.h"
#include "Subscript.h"

//template <typename T>
//using AbstractArrayContainerPtr = std::unique_ptr<AbstractArrayContainer<T>> ;

template <typename T>
class AbstractArrayContainer: public Cloneable<AbstractArrayContainer<T>> {
public:
	AbstractArrayContainer(); 
	AbstractArrayContainer(Order order);
	~AbstractArrayContainer();

	virtual std::auto_ptr<AbstractArrayContainer<T>> create() = 0;
	virtual auto at(Index index)-> std::shared_ptr<T> = 0;
	
	virtual void duplicateTo(AbstractArrayContainer<T>& replica, Range range);
	virtual void translateTo(AbstractArrayContainer<T>& replica, Range range);
	virtual auto at(Subscript subscript)-> std::shared_ptr<T>;
	virtual auto at(Subscript floor, Subscript ceiling)-> std::auto_ptr<AbstractArrayContainer<T>>;
	virtual auto at(Range range)-> std::auto_ptr<AbstractArrayContainer<T>>;
	virtual Integer getSize();
	virtual Order getOrder();

	// Cloneable override declarations
	void duplicateTo(AbstractArrayContainer<T>& replica);
	void translateTo(AbstractArrayContainer<T>& replica);

private:
	Order order_;
};

//begin:  cpp file
template <typename T>
AbstractArrayContainer<T>::AbstractArrayContainer() {
	//noop
}

template <typename T>
AbstractArrayContainer<T>::AbstractArrayContainer(Order order): order_(order) {
	this->create();
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
	Range newRange(range.getCeiling());
	Range::Iterator n = newRange.getIterator(newRange.getFloor());
	for (Range::Iterator i = range.getIterator(range.getFloor()); i != range.getCeiling(); ++i) {
		replica.at(n) = this->at(i);
		++n;
	}
}

template <typename T>
auto AbstractArrayContainer<T>::at(Subscript subscript)-> std::shared_ptr<T> {
	return this->at(subscript.toIndex(order_));
}

template <typename T>
auto AbstractArrayContainer<T>::at(Subscript floor, Subscript ceiling)-> std::auto_ptr<AbstractArrayContainer<T>> {
	return this->at(Range(floor, ceiling));
}

template <typename T>
auto AbstractArrayContainer<T>::at(Range range)-> std::auto_ptr<AbstractArrayContainer<T>> {
	//todo: default implementation warning
	std::auto_ptr<AbstractArrayContainer<T>> replica = this->create();
	this->duplicateTo(*replica, range);
	return replica;
}

template <typename T>
Integer AbstractArrayContainer<T>::getSize() {
	return order_.toIndex();
}

template <typename T>
Order AbstractArrayContainer<T>::getOrder() {
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
//end:    cpp file

//#include "AbstractArrayContainer.cpp"

#endif
