#ifndef __ARRAYCONTAINER_H__
#define __ARRAYCONTAINER_H__

namespace blackbox {
	class ArrayContainer {
	public:
		template <typename T> class Abstract;
		template <typename T> class Simple;
	};
}

#include "ArrayContainer/Abstract.h"
#include "ArrayContainer/Simple.h"

#endif
