#ifndef __ABSTRACTARRAY_H__
#define __ABSTRACTARRAY_H__

#include <memory>

#include "array/Index.h"
#include "array/Range.h"
#include "array/Subscript.h"

#include "event/EventHandler/EventHandler.h"
#include "event/EventMessage/ImplementationWarning.h"

#include "pattern/Prototype.h"

namespace blackbox
{
	// AbstractArray

	// Serves as base class for all array types in blackbox.
	// Cannot be instantiated directly - must be inherited from.
	// Provides standard Matlab-like array functionality for any data type.
	template <typename T> class AbstractArray : public Prototype<AbstractArray<T>>
	{
		class SubArray;

	public:
		// Constructors:
		AbstractArray() = default;
		AbstractArray(Subscript order);
		virtual ~AbstractArray() = default;

		// Accessor methods:
		virtual auto at(Index index) -> T& = 0;
		virtual auto at(Subscript subscript) -> T&;
		virtual auto at(Range range) -> SubArray;
		T& operator [](Index index);
		T& operator [](Subscript subscript);
		AbstractArray<T>& operator [](Range range);

		// Const accessor methods:
		virtual auto at(Index index) const -> T const& = 0;
		virtual auto at(Subscript subscript) const -> T const&;
		virtual auto at(Range range) const -> const SubArray;
		T const& operator [](Index index) const;
		T const& operator [](Subscript subscript) const;
		AbstractArray<T> const& operator [](Range range) const;

		// Meta-data getters:
		virtual Integer getSize() const;
		virtual Subscript getOrder() const;

		virtual AbstractArray<T>& operator =(std::initializer_list<T> values) = 0;
		/*
		virtual std::auto_ptr<AbstractArray<T>> operator +(AbstractArray<T>& that) = 0;

		virtual std::auto_ptr<AbstractArray<T>> operator -(AbstractArray<T>& that) = 0;

		virtual std::auto_ptr<AbstractArray<T>> operator *(AbstractArray<T>& that) = 0;

		virtual std::auto_ptr<AbstractArray<T>> operator /(AbstractArray<T>& that) = 0;
		*/
		virtual std::auto_ptr<AbstractArray<T>> clone() const;

		virtual std::auto_ptr<AbstractArray<T>> create() const;
		virtual std::auto_ptr<AbstractArray<T>> create(Subscript order) const = 0;

	protected:
		// Meta-data:
		Subscript order_;
		Integer size_;

	}; // AbstractArray

} // blackbox

#include "array/Array/SubArray.h"

namespace blackbox
{
	
	template <typename T> AbstractArray<T>::AbstractArray(Subscript order) : order_(order), size_(order.toIndex())
	{
		//noop
	}

	template <typename T> auto AbstractArray<T>::at(Subscript subscript) -> T&
	{
		return this->at(subscript.toIndex(order_));
	}

	template <typename T> auto AbstractArray<T>::at(Range range) -> SubArray
	{
		//TODO implement new EventMessage for range out of bounds
		ASSERT("", range.getCeiling() <= order_);
		return SubArray(this, range);
	}

	template <typename T> T& AbstractArray<T>::operator [](Index index)
	{
		return this->at(index);
	}

	template <typename T> T& AbstractArray<T>::operator [](Subscript subscript)
	{
		return this->at(subscript);
	}

	template <typename T> AbstractArray<T>& AbstractArray<T>::operator [](Range range)
	{
		return this->at(range);
	}

	template <typename T> auto AbstractArray<T>::at(Subscript subscript) const -> T const&
	{
		return this->at(subscript.toIndex(order_));
	}
	
	template <typename T> auto AbstractArray<T>::at(Range range) const -> const SubArray
	{
		//TODO implement new EventMessage for range out of bounds
		ASSERT("", range.getCeiling() <= order_);
		return SubArray(this, range);
	}
	
	template <typename T> T const& AbstractArray<T>::operator [](Index index) const
	{
		return this->at(index);
	}

	template <typename T> T const& AbstractArray<T>::operator [](Subscript subscript) const
	{
		return this->at(subscript);
	}

	template <typename T> AbstractArray<T> const& AbstractArray<T>::operator [](Range range) const
	{
		return this->at(range);
	}

	template <typename T> Integer AbstractArray<T>::getSize() const
	{
		return order_.toIndex();
	}

	template <typename T> Subscript AbstractArray<T>::getOrder() const
	{
		return order_;
	}

	//TODO? determine if AbstractArray::clone() is necessary
	template <typename T> std::auto_ptr<AbstractArray<T>> AbstractArray<T>::clone() const
	{
		WARNING(__IMPLEMENTATION_WARNING__);
		std::auto_ptr<AbstractArray<T>> replica = this->create();
		Range range(order_);
		for (Range::Iterator i = range.getIterator(); i <= range.getCeiling(); i++)
		{
			replica->at(i) = this->at(i);
		}
		return replica;
	}

	//TODO? determine if AbstractArray::create() is necessary
	template <typename T> std::auto_ptr<AbstractArray<T>> AbstractArray<T>::create() const
	{
		return this->create(order_);
	}

} // blackbox

#endif
