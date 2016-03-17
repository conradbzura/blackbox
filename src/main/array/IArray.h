#ifndef __IARRAY_H__
#define __IARRAY_H__

#include <memory>

#include "Index.h"
#include "Range.h"
#include "Subscript.h"
#include "pattern/Prototype.h"

#include "event/EventHandler/EventHandler.h"
#include "event/EventMessage/ImplementationWarning.h"

namespace blackbox 
{
	template <typename T> class ISubArray;
	template <typename T> class IArray : public Prototype<IArray<T>> 
	{
		IArray() = delete; //TODO? implement

	public:
		IArray(Subscript order);

		virtual ~IArray() = default;
		
		// accessor methods
		virtual auto at(Index index) -> T& = 0;
		auto at(Subscript subscript) -> T&;
		virtual auto at(Range range) -> std::auto_ptr<IArray<T>>;

		T& operator [](Index index);
		T& operator [](Subscript subscript);
		std::auto_ptr<IArray<T>> operator [](Range range);

		// const accessor methods
		virtual auto at(Index index) const -> T const& = 0;
		auto at(Subscript subscript) const -> T const&;
		virtual auto at(Range range) const -> std::auto_ptr<const IArray<T>>;

		T const& operator [](Index index) const;
		T const& operator [](Subscript subscript) const;
		std::auto_ptr<const IArray<T>> operator [](Range range) const;


		virtual Integer getSize() const;

		virtual Subscript getOrder() const;

		virtual IArray<T>& operator =(std::initializer_list<T> values) = 0;
		/*
		virtual std::auto_ptr<IArray<T>> operator +(IArray<T>& that) = 0;

		virtual std::auto_ptr<IArray<T>> operator -(IArray<T>& that) = 0;

		virtual std::auto_ptr<IArray<T>> operator *(IArray<T>& that) = 0;

		virtual std::auto_ptr<IArray<T>> operator /(IArray<T>& that) = 0;
		*/
		virtual std::auto_ptr<IArray<T>> clone() const;

		virtual std::auto_ptr<IArray<T>> create() const;
		virtual std::auto_ptr<IArray<T>> create(Subscript order) const = 0;

	protected:
		virtual std::auto_ptr<IArray<T>> getSubArray_(IArray<T>& array, Range range) = 0;
		virtual std::auto_ptr<IArray<T>> getSubArray_(IArray<T> const& array, Range range) const = 0;
		
		Subscript order_;

	};

	template <typename T> IArray<T>::IArray(Subscript order) : order_(order)
	{
		//noop
	}

	template <typename T> auto IArray<T>::at(Subscript subscript) -> T&
	{
		return this->at(subscript.toIndex(order_));
	}

	template <typename T> auto IArray<T>::at(Range range) -> std::auto_ptr<IArray<T>>
	{
		//TODO implement new EventMessage for range out of bounds
		ASSERT("", range.getCeiling() <= order_);
		return this->getSubArray_(*this, range);
	}

	template <typename T> T& IArray<T>::operator [](Index index)
	{
		return this->at(index);
	}

	template <typename T> T& IArray<T>::operator [](Subscript subscript)
	{
		return this->at(subscript);
	}

	template <typename T> std::auto_ptr<IArray<T>> IArray<T>::operator [](Range range)
	{
		return this->at(range);
	}

	template <typename T> auto IArray<T>::at(Subscript subscript) const -> T const&
	{
		return this->at(subscript.toIndex(order_));
	}

	template <typename T> auto IArray<T>::at(Range range) const -> std::auto_ptr<const IArray<T>>
	{
		ASSERT("", range.getCeiling() <= order_); //TODO implement new EventMessage for range out of bounds
		return this->getSubArray_(*this, range);
	}

	template <typename T> T const& IArray<T>::operator [](Index index) const
	{
		return this->at(index);
	}

	template <typename T> T const& IArray<T>::operator [](Subscript subscript) const
	{
		return this->at(subscript);
	}

	template <typename T> std::auto_ptr<const IArray<T>> IArray<T>::operator [](Range range) const
	{
		return this->at(range);
	}

	template <typename T> Integer IArray<T>::getSize() const
	{
		return order_.toIndex();
	}

	template <typename T> Subscript IArray<T>::getOrder() const
	{
		return order_;
	}

	template <typename T> std::auto_ptr<IArray<T>> IArray<T>::clone() const
	{
		WARNING(__IMPLEMENTATION_WARNING__);
		std::auto_ptr<IArray<T>> replica = this->create();
		Range range(order_);
		Range::Iterator n = range.getIterator(range.getFloor());
		for (Range::Iterator i = range.getIterator(range.getFloor()); i <= range.getCeiling(); ++i)
		{
			replica->at(n) = this->at(i);
			++n;
		}
		return replica;
	}

	template <typename T> std::auto_ptr<IArray<T>> IArray<T>::create() const
	{
		return this->create(order_);
	}

} // blackbox

#include "IArray.cpp"

#endif
