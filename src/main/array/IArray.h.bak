#ifndef __IARRAY_H__
#define __IARRAY_H__

#include <memory>

#include "Index.h"
#include "Range.h"
#include "Subscript.h"
#include "pattern/Prototype.h"

namespace blackbox 
{
	template <typename T>
	class IArray: 
		public Prototype<IArray<T>> 
	{

	public:

		// IArray concrete declarations
		IArray() = delete;

		IArray(Subscript order);

		auto at(Subscript subscript) 
			-> std::shared_ptr<T>&;

		auto at(Subscript subscript) const 
			-> std::shared_ptr<T> const&;

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
		virtual std::auto_ptr<IArray<T>> create(Subscript order) const = 0;

		virtual auto at(Index index) 
			-> std::shared_ptr<T>& = 0;

		virtual auto at(Index index) const 
			-> std::shared_ptr<T> const& = 0;
		/*
		virtual std::auto_ptr<IArray<T>> operator +(IArray<T>& that) = 0;

		virtual std::auto_ptr<IArray<T>> operator -(IArray<T>& that) = 0;

		virtual std::auto_ptr<IArray<T>> operator *(IArray<T>& that) = 0;

		virtual std::auto_ptr<IArray<T>> operator /(IArray<T>& that) = 0;
		*/
	protected:

		Subscript order_;

	};

}

#include "IArray.cpp"

#endif
