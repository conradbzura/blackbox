#ifndef __PROTOTYPE_H__
#define __PROTOTYPE_H__

#include <memory>

namespace blackbox {
	template <class C>
	class Prototype {
	public:
		Prototype();
		~Prototype();

		// pure virtual
		virtual std::auto_ptr<C> create() = 0;
		virtual std::auto_ptr<C> clone() = 0;
	};
}

#include "Prototype.cpp"

#endif
