#include "main/array/Array/BasicArray.h"

namespace blackbox {
namespace Arrays {

// _________________
// Constructor(s)...

// BasicArray(Subscript)
template <typename T>
BasicArray<T>::BasicArray(Subscript order)
    : AbstractArray<T>(order)
    , data_(this->getSize())
{
    for (int i = 0; i < order.toIndex(); i++) {
        data_.at(i) = T();
    }
}

// BasicArray(AbstractArray<T> const&)
template <typename T>
BasicArray<T>::BasicArray(AbstractArray<T> const& array)
    : BasicArray<T>(array.getOrder())
{
    // TODO implement new EventMessage for order mismatch
    ASSERT("", array.getOrder() == this->getOrder());
    for (int i = 1; i <= this->getSize(); i++) {
        this->at(i) = array.at(i);
    }
}

// BasicArray(AbstractArray<T>&&)
template <typename T>
BasicArray<T>::BasicArray(AbstractArray<T>&& array)
    : BasicArray(array.getOrder())
{
    // TODO implement new EventMessage for order mismatch
    ASSERT("", array.getOrder() == this->getOrder());
    for (int i = 1; i <= this->getSize(); i++) {
        this->at(i) = array.at(i);
    }
}

// _____________________
// Accessor method(s)...

// at(Index)
template <typename T>
auto
BasicArray<T>::at(Index index) -> T&
{
    // TODO implement new EventMessage for subscript/index out of bounds
    ASSERT("", index <= this->getSize());
    return data_.at(index - 1);
}

// ___________________________
// Const accessor method(s)...

// at(Index) const
template <typename T>
auto
BasicArray<T>::at(Index index) const -> T const&
{
    // TODO implement new EventMessage for subscript/index out of bounds
    ASSERT("", index <= this->getSize());
    return data_.at(index - 1);
}

// _________________________
// Assignment operator(s)...

// operator =(std::initializer_list)
template <typename T>
BasicArray<T>&
BasicArray<T>::operator=(AbstractArray<T> const& array)
{
    // TODO implement new EventMessage for order mismatch
    ASSERT("", array.getOrder() == this->getOrder());
    if (this != &array) {
        BasicArray<T> temporary(array);
        this->swap_(temporary);
    }
    return *this;
}

// operator =(std::initializer_list)
template <typename T>
BasicArray<T>&
BasicArray<T>::operator=(std::initializer_list<T> values)
{
    // TODO implement new EventMessage for order mismatch
    ASSERT("", values.size() == this->getOrder().toIndex());
    int i = 0;
    for (T value : values) {
        data_.at(i) = value;
        i++;
    }
    return *this;
}

// _________________
// Data getter(s)...

// getData_()
template <typename T>
std::vector<T>
BasicArray<T>::getData_()
{
    return data_;
}

// _________________
// Helper methods...

// swap_(AbstractArray<T>&)
template <typename T>
void
BasicArray<T>::swap_(BasicArray<T>& array)
{
    // std::swap(this->data_, array.getData_());
}

template class BasicArray<int>;

}
} // blackbox
