#ifndef __IADDITIONOPERATOR_H__
#define __IADDITIONOPERATOR_H__

#include <memory>

#include "main/array/ArrayStrategy/ArrayOperator/IArrayOperator.h"

namespace blackbox {
template <typename T>
	class iAdditionOperator : public virtual IArrayOperator<T> {
	public:
		virtual ~iAdditionOperator() = default;
		/*
		virtual std::auto_ptr<AbstractArray<T>> operator +(AbstractArray<T>& that) {
			return execute(*this->cast(), that);
		}
		*/
	};
}

#endif
