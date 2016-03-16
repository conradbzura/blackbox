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
	template <typename T>
	class ISubArray;

	template <typename T>
	class IArray: 
		public Prototype<IArray<T>> 
	{

	public:

		// IArray concrete declarations
		IArray() = delete;

		IArray(Subscript order);

		virtual IArray<T>& operator =(std::initializer_list<T> values) = 0;

		auto at(Subscript subscript) 
			-> T&;

		auto at(Subscript subscript) const 
			-> T const&;

		auto at(Subscript floor, Subscript ceiling) 
			-> std::auto_ptr<IArray<T>>;

		auto at(Subscript floor, Subscript ceiling) const 
			-> std::auto_ptr<IArray<T>>;

		// Prototype virtual override declarations
		virtual std::auto_ptr<IArray<T>> clone() const;

		virtual std::auto_ptr<IArray<T>> create() const;

		// IArray virtual declarations
		virtual ~IArray() = default;

		virtual auto at(Range range) 
			-> std::auto_ptr<IArray<T>>;

		virtual auto at(Range range) const 
			-> std::auto_ptr<IArray<T>>;

		virtual Integer getSize() const;

		virtual Subscript getOrder() const;

		// IArray pure virtual declarations
		virtual std::auto_ptr<IArray<T>> create(Subscript order) const = 0; //TODO? make protected

		virtual std::auto_ptr<IArray<T>> createSubArray(IArray<T>& array, Range range) = 0; //TODO? make protected

		virtual auto at(Index index) 
			-> T& = 0;

		virtual auto at(Index index) const 
			-> T const& = 0;
		/*
		virtual std::auto_ptr<IArray<T>> operator +(IArray<T>& that) = 0;

		virtual std::auto_ptr<IArray<T>> operator -(IArray<T>& that) = 0;

		virtual std::auto_ptr<IArray<T>> operator *(IArray<T>& that) = 0;

		virtual std::auto_ptr<IArray<T>> operator /(IArray<T>& that) = 0;
		*/
	protected:

		Subscript order_;

	};

	template <typename T>
	IArray<T>::IArray(Subscript order) :
		order_(order)
	{
		//noop
	}

	template <typename T>
	auto IArray<T>::at(Subscript subscript)
		-> T&
	{
		return this->at(subscript.toIndex(order_));
	}

	template <typename T>
	auto IArray<T>::at(Subscript subscript) const
		-> T const&
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
		return this->createSubArray(*this, range);
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
			replica->at(n) = this->at(i);
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
			replica->at(n) = this->at(i);
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

#include "IArray.cpp"

#endif
