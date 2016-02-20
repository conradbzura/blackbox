#ifdef __ABSTRACTCONTAINER_H__

namespace blackbox {
	namespace array {

		template <typename T>
		AbstractContainer<T>::AbstractContainer(Subscript order) : order_(order) {
			//noop
		}

		template <typename T>
		AbstractContainer<T>::~AbstractContainer() {
			//noop
		}

		template <typename T>
		void AbstractContainer<T>::duplicateTo(AbstractContainer<T>& replica, Range range) {
			//todo: default implementation warning
			this->translateTo(replica, range);
		}

		template <typename T>
		void AbstractContainer<T>::translateTo(AbstractContainer<T>& replica, Range range) {
			//todo: default implementation warning
			Range newRange(range.getOrder());
			Range::Iterator n = newRange.getIterator(newRange.getFloor());
			for (Range::Iterator i = range.getIterator(range.getFloor()); i <= range.getCeiling(); ++i) {
				replica.at(n) = this->at(i);
				++n;
			}
		}

		template <typename T>
		auto AbstractContainer<T>::at(Subscript subscript)-> std::shared_ptr<T>& {
			return this->at(subscript.toIndex(order_));
		}

		template <typename T>
		auto AbstractContainer<T>::at(Subscript floor, Subscript ceiling)-> std::auto_ptr<AbstractContainer<T>> {
			return this->at(Range(floor, ceiling));
		}

		template <typename T>
		auto AbstractContainer<T>::at(Range range)-> std::auto_ptr<AbstractContainer<T>> {
			//todo: default implementation warning
			std::auto_ptr<AbstractContainer<T>> replica = this->create(range.getOrder());
			this->duplicateTo(*replica, range);
			return replica;
		}

		template <typename T>
		Integer AbstractContainer<T>::getSize() {
			return order_.toIndex();
		}

		template <typename T>
		Subscript AbstractContainer<T>::getOrder() {
			return order_;
		}

		template <typename T>
		void AbstractContainer<T>::duplicateTo(AbstractContainer<T>& replica) {
			this->duplicateTo(replica, Range(order_));
		}

		template <typename T>
		void AbstractContainer<T>::translateTo(AbstractContainer<T>& replica) {
			this->translateTo(replica, Range(order_));
		}
	}
}


#endif
