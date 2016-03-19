#ifndef __SUBARRAY_H__
#define __SUBARRAY_H__

namespace blackbox
{
	// SubArray

	// Provides a handle to an AbstractArray object with a specific range.
	// Cannot be instantiated directly - a SubArray object is returned from an AbstractArray object using the at(Range) accessor method.
	template <typename T> class AbstractArray<T>::SubArray : public virtual AbstractArray<T>
	{
		SubArray() = delete;
		SubArray(AbstractArray<T> const& array) = delete;

	public:
		SubArray(SubArray const& array) = default;
		SubArray(AbstractArray<T>* const array, Range range);
		SubArray(const AbstractArray<T>* const array, Range range);
		virtual ~SubArray() = default;

		// Accessor methods:
		auto at(Index index)->T&;
		auto at(Subscript subscript)->T&;
		auto at(Range range)->SubArray;

		// Const accessor methods:
		auto at(Index index) const->T const&;
		auto at(Subscript subscript) const->T const&;
		auto at(Range range) const -> const SubArray;

		virtual std::auto_ptr<AbstractArray<T>> create(Subscript order) const;

		// Assignment operators:
		SubArray& operator =(std::initializer_list<T> values);
		SubArray& operator =(AbstractArray<T> const& array);

	protected:
		union {
			AbstractArray<T>* const array_;
			const AbstractArray<T>* const constArray_;
		};

		Range range_;

	}; // SubArray

} // blackbox

namespace blackbox
{

	template <typename T> AbstractArray<T>::SubArray::SubArray(AbstractArray<T>* const array, Range range) :
		AbstractArray<T>(range.getOrder()), array_(array), range_(range)
	{
	}
	
	template <typename T> AbstractArray<T>::SubArray::SubArray(const AbstractArray<T>* const array, Range range) :
		AbstractArray<T>(range.getOrder()), constArray_(array), range_(range)
	{
	}

	template <typename T> typename AbstractArray<T>::SubArray& AbstractArray<T>::SubArray::operator =(std::initializer_list<T> values)
	{
		//TODO implement new EventMessage for size mismatch
		ASSERT("", values.size() == order_.toIndex());
		Integer i = 1;
		for (T value : values) {
			array_->at(range_.map(Index(i++).toSubscript(order_))) = value;
		}
		return *this;
	}

	template <typename T> typename AbstractArray<T>::SubArray& AbstractArray<T>::SubArray::operator =(AbstractArray<T> const& array)
	{
		//TODO implement new EventMessage for order mismatch
		ASSERT("", array->getOrder() == this->getOrder());
		for (int i = 1; i <= this->getSize(); i++)
		{
			this->at(i) = array.at(i);
		}
		return *this;
	}

	template <typename T> auto AbstractArray<T>::SubArray::at(Index index) -> T&
	{
		//TODO implement new EventMessage for subscript/index out of bounds
		ASSERT("", index <= size_);
		return array_->at(range_.map(index.toSubscript(order_)));
	}

	template <typename T> auto AbstractArray<T>::SubArray::at(Subscript subscript) -> T&
	{
		//TODO implement new EventMessage for subscript/index out of bounds
		ASSERT("", subscript <= order_);
		return array_->at(range_.map(subscript));
	}

	template <typename T> auto AbstractArray<T>::SubArray::at(Range range) -> SubArray
	{
		//TODO implement new EventMessage for range out of bounds
		ASSERT("", range.getCeiling() <= order_);
		return SubArray(array_, range);
	}

	template <typename T> auto AbstractArray<T>::SubArray::at(Index index) const -> T const&
	{
		//TODO implement new EventMessage for subscript/index out of bounds
		ASSERT("", index <= size_);
		return constArray_->at(range_.map(index.toSubscript(order_)));
	}

	template <typename T> auto AbstractArray<T>::SubArray::at(Subscript subscript) const -> T const&
	{
		//TODO implement new EventMessage for subscript/index out of bounds
		ASSERT("", subscript <= order_);
		return constArray_->at(range_.map(subscript));
	}
	
	template <typename T> auto AbstractArray<T>::SubArray::at(Range range) const -> const SubArray
	{
		//TODO implement new EventMessage for range out of bounds
		ASSERT("", range.getCeiling() <= order_);
		return SubArray(constArray_, range);
	}

	template <typename T> std::auto_ptr<AbstractArray<T>> AbstractArray<T>::SubArray::create(Subscript order) const
	{
		return std::auto_ptr<AbstractArray<T>>(); //TODO implement or remove
	}

} // blackbox

#endif
