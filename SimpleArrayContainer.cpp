#ifdef __SIMPLEARRAYCONTAINER_H__

template <typename T>
SimpleArrayContainer<T>::SimpleArrayContainer() {
	//noop
}

template <typename T>
SimpleArrayContainer<T>::SimpleArrayContainer(Subscript order): AbstractArrayContainer<T>(order), data_(order.toIndex()) {
	//noop
}

template <typename T>
SimpleArrayContainer<T>::~SimpleArrayContainer() {
	//noop
}

template <typename T>
SimpleArrayContainer<int>& SimpleArrayContainer<T>::operator =(std::initializer_list<T> values) {
	int i = 0;
	for (T v : values) {
		data_.at(i) = std::shared_ptr<T>(new T(v));
		i++;
	}
	return *this;
}

template <typename T>
std::auto_ptr<AbstractArrayContainer<T>> SimpleArrayContainer<T>::create(Subscript order) {
	return std::auto_ptr<AbstractArrayContainer<T>>(new SimpleArrayContainer<T>(order));
}

template <typename T>
auto SimpleArrayContainer<T>::at(Index index)-> std::shared_ptr<T>& {
	return data_.at(index - 1);
}

#endif
