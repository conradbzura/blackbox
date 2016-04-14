#ifndef __SUBARRAY_H__
#define __SUBARRAY_H__

namespace blackbox
{
	namespace Arrays {
	// SubArray
	// _______________________________________________________________________
	// Provides a handle to an AbstractArray object with a specific range.
	// Cannot be instantiated directly - a SubArray object is returned from an 
	// AbstractArray object using the at(Range) accessor method.
	template <typename T> class AbstractArray<T>::SubArray : public virtual AbstractArray<T>
	{
		SubArray() = delete;
		SubArray(SubArray const& array) = delete;

	public:
		// _________________
		// Constructor(s)...
		SubArray(SubArray&& array) = default;
		SubArray(AbstractArray<T>* const array, Range range);
		SubArray(const AbstractArray<T>* const array, Range range);
		virtual ~SubArray() = default;
		// _____________________
		// Accessor method(s)...
		auto at(Index index) ->	T&;
		auto at(Subscript subscript) -> T&;
		auto at(Range range) ->	SubArray;
		// ___________________________
		// Const accessor method(s)...
		auto at(Index index) const -> T const&;
		auto at(Subscript subscript) const -> T const&;
		auto at(Range range) const -> const SubArray;
		// _________________________
		// Assignment operator(s)...
		SubArray& operator =(SubArray const& array);
		SubArray& operator =(AbstractArray<T> const& array);
		SubArray& operator =(std::initializer_list<T> values);

	protected:
		// ______________________
		// Meta-data getter(s)...
		auto getParent_() -> AbstractArray<T>* const;
		auto getParent_() const -> const AbstractArray<T>* const;
		Range getRange_() const;

	private:
		// ___________________
		// Helper method(s)...
		SubArray& copy_(AbstractArray<T> const& array);

		// ____________
		// Meta-data...
		union { AbstractArray<T>* const parent_; const AbstractArray<T>* const constParent_; };
		Range range_;

	}; // SubArray
	}
} // blackbox

namespace blackbox
{
	namespace Arrays {

	// _________________
	// Constructor(s)...

	// SubArray(AbstractArray<T>* const)
	template <typename T> AbstractArray<T>::SubArray::SubArray(AbstractArray<T>* const array, Range range) :
		AbstractArray<T>(range.getOrder()), parent_(array), range_(range)
	{
	}
	
	// SubArray(const AbstractArray<T>* const)
	template <typename T> AbstractArray<T>::SubArray::SubArray(const AbstractArray<T>* const array, Range range) :
		AbstractArray<T>(range.getOrder()), constParent_(array), range_(range)
	{
	}


	// _____________________
	// Accessor method(s)...

	// at(Index)
	template <typename T> auto AbstractArray<T>::SubArray::at(Index index) -> T&
	{
		//TODO implement new EventMessage for subscript/index out of bounds
		ASSERT("", index <= this->getSize());
		return parent_->at(range_.map(index.toSubscript(order_)));
	}

	// at(Subscript)
	template <typename T> auto AbstractArray<T>::SubArray::at(Subscript subscript) -> T&
	{
		//TODO implement new EventMessage for subscript/index out of bounds
		ASSERT("", subscript <= this->getOrder());
		return parent_->at(range_.map(subscript));
	}

	// at(Range)
	template <typename T> auto AbstractArray<T>::SubArray::at(Range range) -> SubArray
	{
		//TODO implement new EventMessage for range out of bounds
		ASSERT("", range.getCeiling() <= this->getOrder());
		return SubArray(parent_, range);
	}


	// ___________________________
	// Const accessor method(s)...

	// at(Index) const
	template <typename T> auto AbstractArray<T>::SubArray::at(Index index) const -> T const&
	{
		//TODO implement new EventMessage for subscript/index out of bounds
		ASSERT("", index <= this->getSize());
		return constParent_->at(range_.map(index.toSubscript(order_)));
	}

	// at(Subscript) const
	template <typename T> auto AbstractArray<T>::SubArray::at(Subscript subscript) const -> T const&
	{
		//TODO implement new EventMessage for subscript/index out of bounds
		ASSERT("", subscript <= this->getOrder());
		return constParent_->at(range_.map(subscript));
	}
	
	// at(Range) const
	template <typename T> auto AbstractArray<T>::SubArray::at(Range range) const -> const SubArray
	{
		//TODO implement new EventMessage for range out of bounds
		ASSERT("", range.getCeiling() <= this->getOrder());
		return SubArray(constParent_, range);
	}


	// _________________________
	// Assignment operator(s)...

	// operator =(SubArray const&)
	template <typename T> typename AbstractArray<T>::SubArray& AbstractArray<T>::SubArray::operator =(SubArray const& array)
	{
		return this->copy_(array);
	}

	// operator =(AbstractArray<T> const&)
	template <typename T> typename AbstractArray<T>::SubArray& AbstractArray<T>::SubArray::operator =(AbstractArray<T> const& array)
	{
		return this->copy_(array);
	}

	// operator =(std::initializer_list)
	template <typename T> typename AbstractArray<T>::SubArray& AbstractArray<T>::SubArray::operator =(std::initializer_list<T> values)
	{
		//TODO implement new EventMessage for size mismatch
		ASSERT("", values.size() == this->getSize());
		Integer i = 1;
		for (T value : values) {
			parent_->at(range_.map(Index(i++).toSubscript(order_))) = value;
		}
		return *this;
	}


	// ______________________
	// Meta-data getter(s)...

	// getParent_()
	template <typename T> auto AbstractArray<T>::SubArray::getParent_() -> AbstractArray<T>* const
	{
		return parent_;
	}

	// getParent_()
	template <typename T> auto AbstractArray<T>::SubArray::getParent_() const -> const AbstractArray<T>* const
	{
		return constParent_;
	}

	// getRange_()
	template <typename T> Range AbstractArray<T>::SubArray::getRange_() const
	{
		return range_;
	}

	// ___________________
	// Helper method(s)...

	// copy_(AbstractArray<T>)
	template <typename T> typename AbstractArray<T>::SubArray& AbstractArray<T>::SubArray::copy_(AbstractArray<T> const& array)
	{
		//TODO implement new EventMessage for order mismatch
		ASSERT("", array.getOrder() == this->getOrder());
		for (int i = 1; i <= this->getSize(); i++)
		{
			this->at(i) = array.at(i);
		}
		return *this;
	}
	}
} // blackbox

#endif
