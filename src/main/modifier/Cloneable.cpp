#ifdef __CLONEABLE_H__

namespace blackbox {
	namespace modifier {

		template <typename T>
		Cloneable<T>::Cloneable() {
			//noop
		}

		template <typename T>
		Cloneable<T>::~Cloneable() {
			//noop
		}

		template <typename T>
		void Cloneable<T>::cloneTo(T& replica) {
			if (typeid(replica) == typeid(*this)) {
				duplicateTo(replica);
			}
			else {
				translateTo(replica);
			}
		}
	}
}

#endif