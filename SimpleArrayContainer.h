#ifndef __SIMPLEARRAYCONTAINER_H__
#define __SIMPLEARRAYCONTAINER_H__

#include "AbstractArrayContainer.h"

template <typename T>
class SimpleArrayContainer: public AbstractArrayContainer<T> {
public:
	SimpleArrayContainer();
	SimpleArrayContainer(Subscript order);
	~SimpleArrayContainer();

	SimpleArrayContainer<int>& operator =(std::initializer_list<T> values);

	virtual std::auto_ptr<AbstractArrayContainer<T>> create(Subscript order);
	using AbstractArrayContainer<T>::at;
	virtual auto at(Index index)-> std::shared_ptr<T>&;
	void test() {}

protected:
	std::vector<std::shared_ptr<T>> data_;
};

#include "SimpleArrayContainer.cpp"

#endif

