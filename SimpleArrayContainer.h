#ifndef __SIMPLEARRAYCONTAINER_H__
#define __SIMPLEARRAYCONTAINER_H__

#include "AbstractArrayContainer.h"

template <typename T>
class SimpleArrayContainer: public AbstractArrayContainer<T> {
public:
	SimpleArrayContainer();
	~SimpleArrayContainer();

	virtual std::auto_ptr<AbstractArrayContainer<T>> create();
	using AbstractArrayContainer<T>::at;
	virtual auto at(Index index)-> std::shared_ptr<T>;
	void test() {}
};

//begin: .cpp file
template <typename T>
SimpleArrayContainer<T>::SimpleArrayContainer() {
	//noop
}

template <typename T>
SimpleArrayContainer<T>::~SimpleArrayContainer() {
	//noop
}

template <typename T>
std::auto_ptr<AbstractArrayContainer<T>> SimpleArrayContainer<T>::create() {
	return std::auto_ptr<AbstractArrayContainer<T>>(new SimpleArrayContainer<T>());
}

template <typename T>
auto SimpleArrayContainer<T>::at(Index index)-> std::shared_ptr<T> {
	//todo: implement
	return std::shared_ptr<T>(new T());
}
//end: .cpp file

//#include "SimpleArrayContainer.cpp"

#endif

