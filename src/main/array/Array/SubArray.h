#ifndef __SUBARRAY_H__
#define __SUBARRAY_H__

#include "array/Array/ISubArray.h"

namespace blackbox
{
	template <typename T>
	class SubArray:
		public ISubArray<T>
	{

	public:

		// Array concrete declarations
		SubArray() = delete;

		SubArray(IArray<T>& array, Range range);

		SubArray<T>& operator =(std::initializer_list<T> values);

		// Array virtual declarations
		virtual ~SubArray();

		// IArray concrete override declarations
		using ISubArray<T>::at;

		auto at(Index index)
			->T&;

		auto at(Index index) const
			->T const&;

		// IArray virtual override declarations
		virtual std::auto_ptr<IArray<T>> create(Subscript order) const;

		virtual std::auto_ptr<IArray<T>> createSubArray(IArray<T>& array, Range range);

	protected:

		std::vector<T*> data_;

	};

	template <typename T>
	SubArray<T>::SubArray(IArray<T>& array, Range range):
		ISubArray<T>(range.getOrder()),
		data_(range.getOrder().toIndex())
	{
		Range subRange(range.getOrder());
		Range::Iterator s = subRange.getIterator(range.getFloor());
		for (Range::Iterator i = range.getIterator(range.getFloor()); i <= range.getCeiling(); ++i)
		{
			
			data_.at(Subscript(s).toIndex(range.getOrder()) - 1) = &array.at(i);
			++s;
		}
	}

	template <typename T>
	SubArray<T>::~SubArray()
	{
		//noop
	}

	template <typename T>
	SubArray<T>& SubArray<T>::operator =(std::initializer_list<T> values)
	{
		int i = 0;
		for (T value : values) {
			*data_.at(i) = value;
			i++;
		}
		return *this;
	}

	template <typename T>
	auto SubArray<T>::at(Index index)
		-> T&
	{
		return *data_.at(index - 1);
	}

	template <typename T>
	auto SubArray<T>::at(Index index) const
		-> T const&
	{
		return *data_.at(index - 1);
	}

	template <typename T>
	std::auto_ptr<IArray<T>> SubArray<T>::create(Subscript order) const
	{
		//return std::auto_ptr<IArray<T>>(new SubArray<T>(order));
		return std::auto_ptr<IArray<T>>();
	}

	template <typename T>
	std::auto_ptr<IArray<T>> SubArray<T>::createSubArray(IArray<T>& array, Range range)
	{
		return std::auto_ptr<IArray<T>>(new SubArray<T>(array, range));
	}
}

#endif
