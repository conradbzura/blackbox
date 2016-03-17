#ifndef __SUBARRAY_H__
#define __SUBARRAY_H__

#include "array/IArray.h"

namespace blackbox
{
	template <typename T> class Array;
	template <typename T> class SubArray : public IArray<T>
	{
		friend class Array<T>;
		
		SubArray() = delete; //TODO? implement

	public:
		virtual ~SubArray() = default;

		// accessor methods
		using IArray<T>::at;
		auto at(Index index) -> T&;

		// const accessor methods
		auto at(Index index) const -> T const&;

		virtual std::auto_ptr<IArray<T>> create(Subscript order) const;

		SubArray<T>& operator =(std::initializer_list<T> values);

	protected:
		SubArray(IArray<T> const& array, Range range);
		SubArray(SubArray<T> const& array, Range range);

		virtual std::auto_ptr<IArray<T>> getSubArray_(IArray<T>& array, Range range);
		virtual std::auto_ptr<IArray<T>> getSubArray_(IArray<T> const& array, Range range) const;

		std::vector<T*> data_;

	};

	template <typename T> SubArray<T>::SubArray(IArray<T> const& array, Range range) :
		IArray<T>(range.getOrder()),
		data_(range.getOrder().toIndex())
	{
		Range subRange(range.getOrder());
		Range::Iterator s = subRange.getIterator(range.getFloor());
		for (Range::Iterator i = range.getIterator(range.getFloor()); i <= range.getCeiling(); ++i)
		{
			data_.at(Subscript(s).toIndex(range.getOrder()) - 1) = new T(array.at(i));
			++s;
		}
	}

	template <typename T> SubArray<T>::SubArray(SubArray<T> const& array, Range range) :
		ISubArray<T>(range.getOrder()),
		data_(range.getOrder().toIndex())
	{
		Range subRange(range.getOrder());
		Range::Iterator s = subRange.getIterator(range.getFloor());
		for (Range::Iterator i = range.getIterator(range.getFloor()); i <= range.getCeiling(); ++i)
		{
			data_.at(Subscript(s).toIndex(range.getOrder()) - 1) = array.at(i);
			++s;
		}
	}

	template <typename T> SubArray<T>& SubArray<T>::operator =(std::initializer_list<T> values)
	{
		ASSERT("", values.size() == order_.toIndex());
		int i = 0;
		for (T value : values) {
			*data_.at(i) = value;
			i++;
		}
		return *this;
	}

	template <typename T> auto SubArray<T>::at(Index index) -> T&
	{
		//TODO implement new EventMessage for subscript/index out of bounds
		ASSERT("", index <= order_.toIndex());
		return *data_.at(index - 1);
	}

	template <typename T> auto SubArray<T>::at(Index index) const -> T const&
	{
		//TODO implement new EventMessage for subscript/index out of bounds
		ASSERT("", index <= order_.toIndex());
		return *data_.at(index - 1);
	}

	template <typename T> std::auto_ptr<IArray<T>> SubArray<T>::create(Subscript order) const
	{
		return std::auto_ptr<IArray<T>>(); //TODO implement or remove
	}

	template <typename T> std::auto_ptr<IArray<T>> SubArray<T>::getSubArray_(IArray<T>& array, Range range)
	{
		return std::auto_ptr<IArray<T>>(new SubArray<T>(array, range));
	}

	template <typename T> std::auto_ptr<IArray<T>> SubArray<T>::getSubArray_(IArray<T> const& array, Range range) const
	{
		return std::auto_ptr<IArray<T>>(new SubArray<T>(array, range));
	}

} // blackbox

#endif
