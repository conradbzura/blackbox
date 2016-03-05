#ifdef __SINGLETON_H__

namespace blackbox {
	template <class Class>
	Singleton<Class>::Singleton() {
		//noop
	}

	template <class Class>
	Singleton<Class>::~Singleton() {
		//noop
	}

	template <class Class>
	Class* Singleton<Class>::instance_ = nullptr;

	template <class Class>
	Class& Singleton<Class>::Instance() {
		if (instance_ == nullptr) {
			instance_ = new Class;
		}
		return *instance_;
	}

	template <class Class>
	Class& Singleton<Class>::New() {
		instance_ = new Class;
		return *instance_;
	}
}

#endif
