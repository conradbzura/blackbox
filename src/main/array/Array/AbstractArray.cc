#include "main/array/Array/AbstractArray.h"
#include "main/array/Array/SubArray.h"

namespace blackbox {
namespace Arrays {

// _________________
// Constructor(s)...

// AbstractArray(Subscript)
template <typename T>
AbstractArray<T>::AbstractArray(Subscript order)
    : order_(order)
    , size_(order.toIndex())
{
}

// _____________________
// Accessor method(s)...

// at(Subscript)
template <typename T>
auto
AbstractArray<T>::at(Subscript subscript) -> T&
{
    return this->at(subscript.toIndex(order_));
}

// at(Range)
template <typename T>
auto
AbstractArray<T>::at(Range range) -> SubArray
{
    // TODO implement new EventMessage for range out of bounds
    ASSERT("", range.getCeiling() <= order_);
    return SubArray(this, range);
}

// operator [](Index)
template <typename T>
T& AbstractArray<T>::operator[](Index index)
{
    return this->at(index);
}

// operator [](Subscript)
template <typename T>
T& AbstractArray<T>::operator[](Subscript subscript)
{
    return this->at(subscript);
}

// operator [](Range)
template <typename T>
typename AbstractArray<T>::SubArray AbstractArray<T>::operator[](Range range)
{
    return this->at(range);
}

// ___________________________
// Const accessor method(s)...

// at(Subscript) const
template <typename T>
auto
AbstractArray<T>::at(Subscript subscript) const -> T const&
{
    return this->at(subscript.toIndex(order_));
}

// at(Range) const
template <typename T>
auto
AbstractArray<T>::at(Range range) const -> const SubArray
{
    // TODO implement new EventMessage for range out of bounds
    ASSERT("", range.getCeiling() <= order_);
    return SubArray(this, range);
}

// operator [](Index) const
template <typename T>
T const& AbstractArray<T>::operator[](Index index) const
{
    return this->at(index);
}

// operator [](Subscript) const
template <typename T>
T const& AbstractArray<T>::operator[](Subscript subscript) const
{
    return this->at(subscript);
}

// operator [](Range) const
template <typename T>
const typename AbstractArray<T>::SubArray AbstractArray<T>::operator[](
    Range range) const
{
    return this->at(range);
}

// ______________________
// Meta-data getter(s)...

// getSize() const
template <typename T>
Integer
AbstractArray<T>::getSize() const
{
    return order_.toIndex();
}

// getOrder() const
template <typename T>
Subscript
AbstractArray<T>::getOrder() const
{
    return order_;
}

template class AbstractArray<int>;

}
} // blackbox
