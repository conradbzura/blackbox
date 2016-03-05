#ifndef __PROTOTYPE_H__
#define __PROTOTYPE_H__

namespace blackbox {
	template <class C>
	class Prototype {
	public:
		Prototype();
		~Prototype();

		// pure virtual
		virtual C* create() = 0;
		virtual C* clone() = 0;
	};
}

#include "Prototype.cpp"

#endif
