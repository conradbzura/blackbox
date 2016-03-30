#ifndef __ABSTRACTARRAY_H__
#define __ABSTRACTARRAY_H__

#include <memory>

#include "main/array/Index.h"
#include "main/array/Range.h"
#include "main/array/Subscript.h"

#include "main/event/EventHandler/EventHandler.h"
#include "main/event/EventMessage/ImplementationWarning.h"

#include "main/pattern/Prototype.h"

namespace blackbox
{
	// AbstractArray
	// ____________________________________________________________________
	// Serves as base class for all array types in blackbox.
	// Cannot be instantiated directly - must be inherited from.
	// Provides standard Matlab-like array functionality for any data type.
	template <typename T> class AbstractArray
	{
		class SubArray;

	public:
		// _________________
		// Constructor(s)...
		AbstractArray() = default;
		AbstractArray(Subscript order);
		virtual ~AbstractArray() = default;
		// _____________________
		// Accessor method(s)...
		virtual auto at(Index index) ->	T& = 0;
		virtual auto at(Subscript subscript) ->	T&;
		virtual auto at(Range range) ->	SubArray;
		// ___________________________
		// Const accessor method(s)...
		virtual auto at(Index index) const -> T const& = 0;
		virtual auto at(Subscript subscript) const -> T const&;
		virtual auto at(Range range) const -> const SubArray;
		// ______________________
		// Meta-data getter(s)...
		virtual Integer getSize() const;
		virtual Subscript getOrder() const;
		// _________________________
		// Assignment operator(s)...
		virtual AbstractArray<T>& operator =(std::initializer_list<T> values) = 0;
		// ____________________________
		// Member access operator(s)...
		T& operator [](Index index);
		T& operator [](Subscript subscript);
		SubArray operator [](Range range);
		// __________________________________
		// Const member access operator(s)...
		T const& operator [](Index index) const;
		T const& operator [](Subscript subscript) const;
		const SubArray operator [](Range range) const;
		// _________________________
		// Arithmetic operator(s)...
		//TODO
		//virtual AbstractArray<T> operator +(AbstractArray<T>& that) = 0;
		//virtual AbstractArray<T> operator -(AbstractArray<T>& that) = 0;
		//virtual AbstractArray<T> operator *(AbstractArray<T>& that) = 0;
		//virtual AbstractArray<T> operator /(AbstractArray<T>& that) = 0;
		// _________________________
		// Comparison operator(s)...
		//TODO
		//virtual AbstractArray<T> operator >(AbstractArray<T> const& that) const = 0;
		//virtual AbstractArray<T> operator <(AbstractArray<T> const& that) const = 0;
		//virtual AbstractArray<T> operator >=(AbstractArray<T> const& that) const = 0;
		//virtual AbstractArray<T> operator <=(AbstractArray<T> const& that) const = 0;
		//virtual AbstractArray<T> operator ==(AbstractArray<T> const& that) const = 0;
		//virtual AbstractArray<T> operator !=(AbstractArray<T> const& that) const = 0;

	private:
		// ____________
		// Meta-data...
		Integer size_;
		Subscript order_;

	}; // AbstractArray

} // blackbox

#include "main/array/Array/SubArray.h"

namespace blackbox
{

	// _________________
	// Constructor(s)...
	
	// AbstractArray(Subscript)
	template <typename T> AbstractArray<T>::AbstractArray(Subscript order) : order_(order), size_(order.toIndex())
	{
	}


	// _____________________
	// Accessor method(s)...
	
	// at(Subscript)
	template <typename T> auto AbstractArray<T>::at(Subscript subscript) -> T&
	{
		return this->at(subscript.toIndex(order_));
	}

	// at(Range)
	template <typename T> auto AbstractArray<T>::at(Range range) -> SubArray
	{
		//TODO implement new EventMessage for range out of bounds
		ASSERT("", range.getCeiling() <= order_);
		return SubArray(this, range);
	}

	// operator [](Index)
	template <typename T> T& AbstractArray<T>::operator [](Index index)
	{
		return this->at(index);
	}

	// operator [](Subscript)
	template <typename T> T& AbstractArray<T>::operator [](Subscript subscript)
	{
		return this->at(subscript);
	}

	// operator [](Range)
	template <typename T> typename AbstractArray<T>::SubArray AbstractArray<T>::operator [](Range range)
	{
		return this->at(range);
	}


	// ___________________________
	// Const accessor method(s)...
	
	// at(Subscript) const
	template <typename T> auto AbstractArray<T>::at(Subscript subscript) const -> T const&
	{
		return this->at(subscript.toIndex(order_));
	}

	// at(Range) const
	template <typename T> auto AbstractArray<T>::at(Range range) const -> const SubArray
	{
		//TODO implement new EventMessage for range out of bounds
		ASSERT("", range.getCeiling() <= order_);
		return SubArray(this, range);
	}

	// operator [](Index) const
	template <typename T> T const& AbstractArray<T>::operator [](Index index) const
	{
		return this->at(index);
	}

	// operator [](Subscript) const
	template <typename T> T const& AbstractArray<T>::operator [](Subscript subscript) const
	{
		return this->at(subscript);
	}

	// operator [](Range) const
	template <typename T> const typename AbstractArray<T>::SubArray AbstractArray<T>::operator [](Range range) const
	{
		return this->at(range);
	}


	// ______________________
	// Meta-data getter(s)...
	
	// getSize() const
	template <typename T> Integer AbstractArray<T>::getSize() const
	{
		return order_.toIndex();
	}

	// getOrder() const
	template <typename T> Subscript AbstractArray<T>::getOrder() const
	{
		return order_;
	}

} // blackbox

#endif
