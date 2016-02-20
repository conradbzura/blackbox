#ifdef __SIMPLECONTAINER_H__

namespace blackbox {
	namespace array {

		template <typename T>
		SimpleContainer<T>::SimpleContainer(Subscript order) : AbstractContainer<T>(order), data_(order.toIndex()) {
			//noop
		}

		template <typename T>
		SimpleContainer<T>::~SimpleContainer() {
			//noop
		}

		template <typename T>
		SimpleContainer<T>& SimpleContainer<T>::operator =(std::initializer_list<T> values) {
			int i = 0;
			for (T v : values) {
				data_.at(i) = std::shared_ptr<T>(new T(v));
				i++;
			}
			return *this;
		}

		template <typename T>
		std::auto_ptr<AbstractContainer<T>> SimpleContainer<T>::create(Subscript order) {
			return std::auto_ptr<AbstractContainer<T>>(new SimpleContainer<T>(order));
		}

		template <typename T>
		auto SimpleContainer<T>::at(Index index)-> std::shared_ptr<T>& {
			return data_.at(index - 1);
		}
	}
}

#endif
