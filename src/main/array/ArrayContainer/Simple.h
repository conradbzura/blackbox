#ifndef __SIMPLEARRAYCONTAINER_H__
#define __SIMPLEARRAYCONTAINER_H__

//#include "ArrayContainer.h"

#include "array/Index.h"
#include "array/Range.h"
#include "array/Subscript.h"

namespace blackbox {
	template <typename T>
	class SimpleArrayContainer : public AbstractArrayContainer<T> {
	public:
		SimpleArrayContainer() = delete;
		SimpleArrayContainer(Subscript order);
		~SimpleArrayContainer();
		SimpleArrayContainer<T>& operator =(std::initializer_list<T> values);

		// Abstract override declarations
		using AbstractArrayContainer<T>::at;
		auto at(Index index) -> std::shared_ptr<T>&;
		std::auto_ptr<AbstractArrayContainer<T>> create(Subscript order);

	protected:
		std::vector<std::shared_ptr<T>> data_;
	};
}

#include "Simple.cpp"

#endif

