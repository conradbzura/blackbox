#ifndef __ABSTRACTARRAYSTRATEGY_H__
#define __ABSTRACTARRAYSTRATEGY_H__

#include "Array/IArray.h"

namespace blackbox {
	template <typename T>
	class ArrayStrategy : IArray<T> {
	public:
		virtual ~ArrayStrategy() = default;
	};
}

#endif
