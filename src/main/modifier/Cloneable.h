#ifndef __CLONEABLE_H__
#define __CLONEABLE_H__

namespace blackbox {
	namespace modifier {
		template <typename T>
		class Cloneable {
		public:
			Cloneable();
			~Cloneable();

			// pure virtual
			virtual void duplicateTo(T& replica) = 0;
			virtual void translateTo(T& replica) = 0;

			// virtual
			virtual void cloneTo(T& replica);
		};
	}
}

#include "modifier/Cloneable.cpp"

#endif
