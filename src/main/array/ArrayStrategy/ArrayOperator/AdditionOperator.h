#ifndef __ADDITIONOPERATOR_H__
#define __ADDITIONOPERATOR_H__

#include <memory>

#include "event/EventHandler/EventHandler.h"

#include "iAdditionOperator.h"

namespace blackbox {
	template <typename T>
	class AdditionOperator : public virtual iAdditionOperator<T> {
	public:
		std::auto_ptr<AbstractArray<T>> execute(AbstractArray<T> const& left, AbstractArray<T> const& right) {
			ASSERT("", left.getOrder() == right.getOrder());
			std::auto_ptr<AbstractArray<T>> sum = right.create(right.getOrder());
			for (int i = 1; i <= right.getSize(); i++) {
				sum->at(i) = left.at(i) + right.at(i);
			}
			return sum;
		}
	};
}

#endif
