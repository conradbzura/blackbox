#ifndef __ARRAY_H__
#define __ARRAY_H__

#include "array/IArray.h"
#include "array/ArrayStrategy/ArrayOperator/AdditionOperator.h"
#include "array/Index.h"
#include "array/Range.h"
#include "array/Subscript.h"

namespace blackbox 
{
	template <typename T>
	class BasicArray : public virtual IArray<T>, public virtual AdditionOperator<T> 
	{
		BasicArray() = delete;

	public:
		BasicArray(Subscript order);

		virtual ~BasicArray() = default;
		
		// accessor methods
		using IArray<T>::at;
		auto at(Index index) -> T&;

		// const accessor methods
		auto at(Index index) const -> T const&;

		BasicArray<T>& operator =(std::initializer_list<T> values);

		virtual std::auto_ptr<IArray<T>> create(Subscript order) const;

	protected:
		std::vector<T> data_;

		

	};

	template <typename T>
	BasicArray<T>::BasicArray(Subscript order) : IArray<T>(order), data_(size_)
	{
		for (int i = 0; i < order.toIndex(); i++) {
			data_.at(i) = T();
		}
	}

	template <typename T>
	BasicArray<T>& BasicArray<T>::operator =(std::initializer_list<T> values)
	{
		//TODO implement new EventMessage for order mismatch
		ASSERT("", values.size() == order_.toIndex());
		int i = 0;
		for (T value : values) {
			data_.at(i) = value;
			i++;
		}
		return *this;
	}

	template <typename T>
	auto BasicArray<T>::at(Index index) -> T&
	{
		//TODO implement new EventMessage for subscript/index out of bounds
		ASSERT("", index <= order_.toIndex());
		return data_.at(index - 1);
	}

	template <typename T>
	auto BasicArray<T>::at(Index index) const -> T const&
	{
		//TODO implement new EventMessage for subscript/index out of bounds
		ASSERT("", index <= order_.toIndex());
		return data_.at(index - 1);
	}

	template <typename T>
	std::auto_ptr<IArray<T>> BasicArray<T>::create(Subscript order) const
	{
		return std::auto_ptr<IArray<T>>(new BasicArray<T>(order));
	}

} // blackbox

#include "BasicArray.cpp"

#endif

