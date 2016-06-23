#include "main/array/Array/SubArray.h"

namespace blackbox {
namespace Arrays {

// Constructor(s)...

// SubArray(AbstractArray<T>* const)
template <typename T>
AbstractArray<T>::SubArray::SubArray(AbstractArray<T>* const array, Range range)
    : AbstractArray<T>(range.getOrder())
    , parent_(array)
    , range_(range)
{
}

// SubArray(const AbstractArray<T>* const)
template <typename T>
AbstractArray<T>::SubArray::SubArray(const AbstractArray<T>* const array,
                                     Range range)
    : AbstractArray<T>(range.getOrder())
    , constParent_(array)
    , range_(range)
{
}

// Accessor method(s)...

// at(Index)
template <typename T>
auto
AbstractArray<T>::SubArray::at(Index index) -> T&
{
    // TODO implement new EventMessage for subscript/index out of bounds
    ASSERT("", index <= this->getSize());
    return parent_->at(range_.map(index.toSubscript(order_)));
}

// at(Subscript)
template <typename T>
auto
AbstractArray<T>::SubArray::at(Subscript subscript) -> T&
{
    // TODO implement new EventMessage for subscript/index out of bounds
    ASSERT("", subscript <= this->getOrder());
    return parent_->at(range_.map(subscript));
}

// at(Range)
template <typename T>
auto
AbstractArray<T>::SubArray::at(Range range) -> SubArray
{
    // TODO implement new EventMessage for range out of bounds
    ASSERT("", range.getCeiling() <= this->getOrder());
    return SubArray(parent_, range);
}

// Const accessor method(s)...

// at(Index) const
template <typename T>
auto
AbstractArray<T>::SubArray::at(Index index) const -> T const&
{
    // TODO implement new EventMessage for subscript/index out of bounds
    ASSERT("", index <= this->getSize());
    return constParent_->at(range_.map(index.toSubscript(order_)));
}

// at(Subscript) const
template <typename T>
auto
AbstractArray<T>::SubArray::at(Subscript subscript) const -> T const&
{
    // TODO implement new EventMessage for subscript/index out of bounds
    ASSERT("", subscript <= this->getOrder());
    return constParent_->at(range_.map(subscript));
}

// at(Range) const
template <typename T>
auto
AbstractArray<T>::SubArray::at(Range range) const -> const SubArray
{
    // TODO implement new EventMessage for range out of bounds
    ASSERT("", range.getCeiling() <= this->getOrder());
    return SubArray(constParent_, range);
}

// Assignment operator(s)...

// operator =(SubArray const&)
template <typename T>
typename AbstractArray<T>::SubArray&
AbstractArray<T>::SubArray::operator=(SubArray const& array)
{
    return this->copy_(array);
}

// operator =(AbstractArray<T> const&)
template <typename T>
typename AbstractArray<T>::SubArray&
AbstractArray<T>::SubArray::operator=(AbstractArray<T> const& array)
{
    return this->copy_(array);
}

// operator =(std::initializer_list)
template <typename T>
typename AbstractArray<T>::SubArray&
AbstractArray<T>::SubArray::operator=(std::initializer_list<T> values)
{
    // TODO implement new EventMessage for size mismatch
    ASSERT("", values.size() == this->getSize());
    Integer i = 1;
    for (T value : values) {
        parent_->at(range_.map(Index(i++).toSubscript(order_))) = value;
    }
    return *this;
}

// Meta-data getter(s)...

// getParent_()
template <typename T>
auto
AbstractArray<T>::SubArray::getParent_() -> AbstractArray<T>* const
{
    return parent_;
}

// getParent_()
template <typename T>
auto
AbstractArray<T>::SubArray::getParent_() const -> const AbstractArray<T>* const
{
    return constParent_;
}

// getRange_()
template <typename T>
Range
AbstractArray<T>::SubArray::getRange_() const
{
    return range_;
}

// Helper method(s)...

// copy_(AbstractArray<T>)
template <typename T>
typename AbstractArray<T>::SubArray&
AbstractArray<T>::SubArray::copy_(AbstractArray<T> const& array)
{
    // TODO implement new EventMessage for order mismatch
    ASSERT("", array.getOrder() == this->getOrder());
    for (int i = 1; i <= this->getSize(); i++) {
        this->at(i) = array.at(i);
    }
    return *this;
}

template class AbstractArray<int>::SubArray;

}
} // blackbox
