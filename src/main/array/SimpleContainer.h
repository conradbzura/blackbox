#ifndef __SIMPLECONTAINER_H__
#define __SIMPLECONTAINER_H__

#include "AbstractContainer.h"

namespace blackbox {
	namespace array {
		template <typename T>
		class SimpleContainer : public AbstractContainer<T> {
		public:
			SimpleContainer() = delete;
			SimpleContainer(Subscript order);
			~SimpleContainer();
			SimpleContainer<T>& operator =(std::initializer_list<T> values);

			// AbstractContainer override declarations
			using AbstractContainer<T>::at;
			auto at(Index index)->std::shared_ptr<T>&;
			std::auto_ptr<AbstractContainer<T>> create(Subscript order);

		protected:
			std::vector<std::shared_ptr<T>> data_;
		};
	}
}

#include "SimpleContainer.cpp"

#endif

