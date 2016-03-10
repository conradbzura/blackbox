#ifndef __ABSTRACTARRAYCONTAINER_H__
#define __ABSTRACTARRAYCONTAINER_H__

#include <memory>

#include "array/Index.h"
#include "array/Range.h"
#include "array/Subscript.h"
#include "pattern/Prototype.h"

namespace blackbox {
	template <typename T>
	class AbstractArrayContainer : public Prototype<AbstractArrayContainer<T>> {
		//using Abstract = AbstractArrayContainer;
	public:
		AbstractArrayContainer() = delete;
		AbstractArrayContainer(Subscript order);
		~AbstractArrayContainer();

		auto at(Subscript subscript) -> std::shared_ptr<T>&;
		auto at(Subscript floor, Subscript ceiling) -> std::auto_ptr<AbstractArrayContainer<T>>;
			
		// pure virtual
		virtual std::auto_ptr<AbstractArrayContainer<T>> create(Subscript order) = 0;
		virtual auto at(Index index) -> std::shared_ptr<T>& = 0;

		// virtual
		virtual auto at(Range range) -> std::auto_ptr<AbstractArrayContainer<T>>;
		virtual Integer getSize();
		virtual Subscript getOrder();

		// Prototype override declarations
		virtual std::auto_ptr<AbstractArrayContainer<T>> clone();
		virtual std::auto_ptr<AbstractArrayContainer<T>> create();

	protected:
		Subscript order_;
	};
}

#include "Abstract.cpp"

#endif
