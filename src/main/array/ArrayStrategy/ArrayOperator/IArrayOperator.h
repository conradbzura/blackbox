#ifndef __IARRAYOPERATOR_H__
#define __IARRAYOPERATOR_H__

namespace blackbox {
	template <typename T>
	class AbstractArray;
	template <typename T>
	class IArrayOperator {
	public:
		virtual ~IArrayOperator() = default;
		/*
		operator const AbstractArray<T>*() {
			return dynamic_cast<const AbstractArray<T>*>(this);
		}
		
		const AbstractArray<T>* cast() {
			return dynamic_cast<const AbstractArray<T>*>(this);
		}
		
		virtual std::auto_ptr<AbstractArray<T>> execute(AbstractArray<T> const& left, AbstractArray<T> const& right) = 0;
		*/
	};
}

#endif

