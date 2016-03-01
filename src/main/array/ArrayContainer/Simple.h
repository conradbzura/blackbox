#ifndef __SIMPLEARRAYCONTAINER_H__
#define __SIMPLEARRAYCONTAINER_H__

//#include "ArrayContainer.h"

#include "Index.h"
#include "Range.h"
#include "Subscript.h"

namespace blackbox {
	template <typename T>
	class ArrayContainer::Simple : public ArrayContainer::Abstract<T> {
	public:
		Simple() = delete;
		Simple(Subscript order);
		~Simple();
		Simple<T>& operator =(std::initializer_list<T> values);

		// Abstract override declarations
		using Abstract<T>::at;
		auto at(Index index) -> std::shared_ptr<T>&;
		std::auto_ptr<Abstract<T>> create(Subscript order);

	protected:
		std::vector<std::shared_ptr<T>> data_;
	};
}

#include "Simple.cpp"

#endif

