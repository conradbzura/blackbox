#ifdef __IARRAY_H__

#include <typeinfo>

#include "event/EventHandler/EventHandler.h"
#include "event/EventMessage/ImplementationWarning.h"

namespace blackbox {

	template <typename T>
	IArray<T>::IArray(Subscript order): 
		order_(order) 
	{
		//noop
	}

	template <typename T>
	auto IArray<T>::at(Subscript subscript) 
		-> std::shared_ptr<T>& 
	{
		return this->at(subscript.toIndex(order_));
	}
	
	template <typename T>
	auto IArray<T>::at(Subscript subscript) const 
		-> std::shared_ptr<T> const& 
	{
		return this->at(subscript.toIndex(order_));
	}
	
	template <typename T>
	auto IArray<T>::at(Subscript floor, Subscript ceiling) 
		-> std::auto_ptr<IArray<T>> 
	{
		return this->at(Range(floor, ceiling));
	}
	
	template <typename T>
	auto IArray<T>::at(Subscript floor, Subscript ceiling) const 
		-> std::auto_ptr<IArray<T>> 
	{
		return this->at(Range(floor, ceiling));
	}
	
	template <typename T>
	auto IArray<T>::at(Range range) 
		-> std::auto_ptr<IArray<T>> 
	{
		WARNING(__IMPLEMENTATION_WARNING__);
		std::auto_ptr<IArray<T>> replica = this->create(range.getOrder());
		Range newRange(range.getOrder());
		Range::Iterator n = newRange.getIterator(range.getFloor());
		for (Range::Iterator i = range.getIterator(range.getFloor()); i <= range.getCeiling(); ++i) 
		{
			replica->at(n) = this->at(i);
			++n;
		}
		return replica;
	}
	
	template <typename T>
	auto IArray<T>::at(Range range) const 
		-> std::auto_ptr<IArray<T>> 
	{
		WARNING(__IMPLEMENTATION_WARNING__);
		std::auto_ptr<IArray<T>> replica = this->create(range.getOrder());
		Range newRange(range.getOrder());
		Range::Iterator n = newRange.getIterator(range.getFloor());
		for (Range::Iterator i = range.getIterator(range.getFloor()); i <= range.getCeiling(); ++i) 
		{
			*replica->at(n) = *this->at(i);
			++n;
		}
		return replica;
	}

	template <typename T>
	Integer IArray<T>::getSize() const 
	{
		return order_.toIndex();
	}

	template <typename T>
	Subscript IArray<T>::getOrder() const 
	{
		return order_;
	}

	template <typename T>
	std::auto_ptr<IArray<T>> IArray<T>::clone() const 
	{
		WARNING(__IMPLEMENTATION_WARNING__);
		std::auto_ptr<IArray<T>> replica = this->create();
		Range range(order_);
		Range::Iterator n = range.getIterator(range.getFloor());
		for (Range::Iterator i = range.getIterator(range.getFloor()); i <= range.getCeiling(); ++i) 
		{
			*replica->at(n) = *this->at(i);
			++n;
		}
		return replica;
	}

	template <typename T>
	std::auto_ptr<IArray<T>> IArray<T>::create() const 
	{
		return this->create(order_);
	}

}


#endif
