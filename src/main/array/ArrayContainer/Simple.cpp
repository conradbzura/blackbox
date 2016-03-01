#ifdef __SIMPLEARRAYCONTAINER_H__

namespace blackbox {

	template <typename T>
	ArrayContainer::Simple<T>::Simple(Subscript order) : Abstract<T>(order), data_(order.toIndex()) {
		//noop
	}

	template <typename T>
	ArrayContainer::Simple<T>::~Simple() {
		//noop
	}

	template <typename T>
	ArrayContainer::Simple<T>& ArrayContainer::Simple<T>::operator =(std::initializer_list<T> values) {
		int i = 0;
		for (T v : values) {
			data_.at(i) = std::shared_ptr<T>(new T(v));
			i++;
		}
		return *this;
	}

	template <typename T>
	auto ArrayContainer::Simple<T>::at(Index index) -> std::shared_ptr<T>& {
		return data_.at(index - 1);
	}

	template <typename T>
	std::auto_ptr<ArrayContainer::Abstract<T>> ArrayContainer::Simple<T>::create(Subscript order) {
		return std::auto_ptr<Abstract<T>>(new Simple<T>(order));
	}
}

#endif
