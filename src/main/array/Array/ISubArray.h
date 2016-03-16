#ifndef __ISUBARRAY_H__
#define __ISUBARRAY_H__

#include "array\IArray.h"

namespace blackbox
{
	template <typename T>
	class ISubArray:
		public IArray<T>
	{
	public:
		ISubArray() = delete;

		ISubArray(Subscript order);

		using IArray<T>::at;

		virtual auto at(Range range)
			-> std::auto_ptr<IArray<T>>;

		virtual ~ISubArray() = default;
	};

	template <typename T>
	ISubArray<T>::ISubArray(Subscript order):
		IArray<T>(order)
	{
		//noop
	}

	template <typename T>
	auto ISubArray<T>::at(Range range)
		-> std::auto_ptr<IArray<T>>
	{
		WARNING(__IMPLEMENTATION_WARNING__);
		std::auto_ptr<IArray<T>> subArray = this->createSubArray(*this, range.getOrder());
		Range newRange(range.getOrder());
		Range::Iterator n = newRange.getIterator(range.getFloor());
		for (Range::Iterator i = range.getIterator(range.getFloor()); i <= range.getCeiling(); ++i)
		{
			subArray->at(n) = this->at(i);
			++n;
		}
		return subArray;
	}
}

#endif
