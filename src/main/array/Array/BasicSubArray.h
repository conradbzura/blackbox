#ifndef __SUBARRAY_H__
#define __SUBARRAY_H__

#include "array/IArray.h"

namespace blackbox
{
	template <typename T> class BasicArray;
	template <typename T> class BasicArrayHandle : public virtual IArray<T>
	{
		friend class BasicArray<T>;
		
		BasicArrayHandle() = delete; //TODO? implement

	public:
		virtual ~BasicArrayHandle() = default;

		// accessor methods
		using IArray<T>::at;
		auto at(Index index) -> T&;

		// const accessor methods
		auto at(Index index) const -> T const&;

		virtual std::auto_ptr<IArray<T>> create(Subscript order) const;

		BasicArrayHandle<T>& operator =(std::initializer_list<T> values);

	protected:
		BasicArrayHandle(IArray<T> const& array, Range range);
		BasicArrayHandle(BasicArrayHandle<T> const& array, Range range);

		virtual std::auto_ptr<IArray<T>> getHandle_(IArray<T>& array, Range range);
		virtual std::auto_ptr<IArray<T>> getHandle_(IArray<T> const& array, Range range) const;

		std::vector<T*> data_;

	};

	template <typename T> BasicArrayHandle<T>::BasicArrayHandle(IArray<T> const& array, Range range) :
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

	template <typename T> BasicArrayHandle<T>::BasicArrayHandle(BasicArrayHandle<T> const& array, Range range) :
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

	template <typename T> BasicArrayHandle<T>& BasicArrayHandle<T>::operator =(std::initializer_list<T> values)
	{
		//TODO implement new EventMessage for order mismatch
		ASSERT("", values.size() == order_.toIndex());
		int i = 0;
		for (T value : values) {
			*data_.at(i) = value;
			i++;
		}
		return *this;
	}

	template <typename T> auto BasicArrayHandle<T>::at(Index index) -> T&
	{
		//TODO implement new EventMessage for subscript/index out of bounds
		ASSERT("", index <= order_.toIndex());
		return *data_.at(index - 1);
	}

	template <typename T> auto BasicArrayHandle<T>::at(Index index) const -> T const&
	{
		//TODO implement new EventMessage for subscript/index out of bounds
		ASSERT("", index <= order_.toIndex());
		return *data_.at(index - 1);
	}

	template <typename T> std::auto_ptr<IArray<T>> BasicArrayHandle<T>::create(Subscript order) const
	{
		return std::auto_ptr<IArray<T>>(); //TODO implement or remove
	}

	template <typename T> std::auto_ptr<IArray<T>> BasicArrayHandle<T>::getHandle_(IArray<T>& array, Range range)
	{
		return std::auto_ptr<IArray<T>>(new BasicArrayHandle<T>(array, range));
	}

	template <typename T> std::auto_ptr<IArray<T>> BasicArrayHandle<T>::getHandle_(IArray<T> const& array, Range range) const
	{
		return std::auto_ptr<IArray<T>>(new BasicArrayHandle<T>(array, range));
	}

} // blackbox

#endif
