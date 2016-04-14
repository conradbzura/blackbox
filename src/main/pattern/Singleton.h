#ifndef __SINGLETON_H__
#define __SINGLETON_H__

namespace blackbox {

	template <class Class>
	class Singleton {
	public:
		static Class& Instance();
		static Class& New();

	protected:
		Singleton() = default;
		~Singleton() = default;

	private:
		Singleton(Singleton const&) = delete;
		Singleton& operator =(Singleton const&) = delete;

		static Class* instance_;
	};

}

#include "Singleton.cc"

#endif
