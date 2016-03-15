#ifndef __IARRAYOPERATOR_H__
#define __IARRAYOPERATOR_H__

namespace blackbox {
	template <typename T>
	class IArray;
	template <typename T>
	class IArrayOperator {
	public:
		virtual ~IArrayOperator() = default;
		operator const IArray<T>*() {
			return dynamic_cast<const IArray<T>*>(this);
		}
		
		const IArray<T>* cast() {
			return dynamic_cast<const IArray<T>*>(this);
		}
		
		virtual std::auto_ptr<IArray<T>> execute(IArray<T> const& left, IArray<T> const& right) = 0;
	};
}

#endif

