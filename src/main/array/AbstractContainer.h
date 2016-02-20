#ifndef __ABSTRACTCONTAINER_H__
#define __ABSTRACTCONTAINER_H__

#include <memory>

#include "modifier/Cloneable.h"
#include "Index.h"
#include "Range.h"
#include "Subscript.h"

namespace blackbox {
	namespace array {
		template <typename T>
		class AbstractContainer : public modifier::Cloneable<AbstractContainer<T>> {
		public:
			AbstractContainer() = delete;
			AbstractContainer(Subscript order);
			~AbstractContainer();

			auto at(Subscript subscript) -> std::shared_ptr<T>&;
			auto at(Subscript floor, Subscript ceiling) -> std::auto_ptr<AbstractContainer<T>>;
			
			// pure virtual
			virtual std::auto_ptr<AbstractContainer<T>> create(Subscript order) = 0;
			virtual auto at(Index index) -> std::shared_ptr<T>& = 0;

			// virtual
			virtual void duplicateTo(AbstractContainer<T>& replica, Range range);
			virtual void translateTo(AbstractContainer<T>& replica, Range range);
			virtual auto at(Range range) -> std::auto_ptr<AbstractContainer<T>>;
			virtual Integer getSize();
			virtual Subscript getOrder();

			// Cloneable override declarations
			void duplicateTo(AbstractContainer<T>& replica);
			void translateTo(AbstractContainer<T>& replica);

		protected:
			Subscript order_;
		};
	}
}

#include "AbstractContainer.cpp"

#endif
