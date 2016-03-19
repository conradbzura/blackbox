#ifndef __SUBARRAY_H__
#define __SUBARRAY_H__

namespace blackbox
{
	//template <typename T> class IArray;
	template <typename T> class IArray<T>::SubArray : public virtual IArray<T>
	{
		//friend class BasicArray<T>;

		SubArray() = delete; //TODO? implement

	public:
		virtual ~SubArray() = default;

		// accessor methods
		using IArray<T>::at;
		auto at(Index index)->T&;

		// const accessor methods
		auto at(Index index) const->T const&;

		virtual std::auto_ptr<IArray<T>> create(Subscript order) const;

		SubArray& operator =(std::initializer_list<T> values);

		SubArray(IArray<T>* const array, Range range);
		SubArray(const IArray<T>* const array, Range range);
		//SubArray(typename SubArray& array, Range range);

	protected:
		std::vector<T*> data_;

		union {
			IArray<T>* const array_;
			const IArray<T>* const constArray_;
		};

		bool isConst_ = false;

		Range range_;
	};

	template <typename T> IArray<T>::SubArray::SubArray(IArray<T>* const array, Range range) :
		IArray<T>(range.getOrder()), array_(array), range_(range), isConst_(false)
	{
	}
	
	template <typename T> IArray<T>::SubArray::SubArray(const IArray<T>* const array, Range range) :
		IArray<T>(range.getOrder()), constArray_(array), range_(range), isConst_(true)
	{
	}
	//TODO implement copy constructor
	/*
	template <typename T> IArray<T>::SubArray::SubArray(IArray<T>::SubArray& array, Range range) :
		IArray<T>(range.getOrder())
	{
		array_ = array;
	}
	*/
	template <typename T> typename IArray<T>::SubArray& IArray<T>::SubArray::operator =(std::initializer_list<T> values)
	{
		//TODO implement new EventMessage for order mismatch
		ASSERT("", values.size() == order_.toIndex());
		Integer i = 1;
		for (T value : values) {
			array_->at(range_.map(Index(i++).toSubscript(order_))) = value;
		}
		return *this;
	}

	template <typename T> auto IArray<T>::SubArray::at(Index index) -> T&
	{
		//TODO implement new EventMessage for subscript/index out of bounds
		ASSERT("", index <= size_);
		return array_->at(index);
	}

	template <typename T> auto IArray<T>::SubArray::at(Index index) const -> T const&
	{
		//TODO implement new EventMessage for subscript/index out of bounds
		ASSERT("", index <= size_);
		return constArray_->at(index);
	}

	template <typename T> std::auto_ptr<IArray<T>> IArray<T>::SubArray::create(Subscript order) const
	{
		return std::auto_ptr<IArray<T>>(); //TODO implement or remove
	}

} // blackbox

#endif
