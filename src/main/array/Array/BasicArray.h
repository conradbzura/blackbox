#ifndef __BASICARRAY_H__
#define __BASICARRAY_H__

#include <utility>

#include "main/array/Array/AbstractArray.h"
#include "main/array/Index.h"
#include "main/array/Range.h"
#include "main/array/Subscript.h"

namespace blackbox {
namespace Arrays {
// BasicArray
// __________________________________________________
// Provides a simple implementation of AbstractArray.
// Must be instantiated with an order.
template <typename T>
class BasicArray : public virtual AbstractArray<T>
{
    BasicArray() = delete;

  public:
    // _________________
    // Constructor(s)...
    BasicArray(Subscript order);
    BasicArray(BasicArray<T> const& array) = default;
    BasicArray(BasicArray<T>&& array) = default;
    BasicArray(AbstractArray<T> const& array);
    BasicArray(AbstractArray<T>&& array);
    virtual ~BasicArray() = default;
    // _____________________
    // Accessor method(s)...
    using AbstractArray<T>::at;
    auto at(Index index) -> T&;
    // ___________________________
    // Const accessor method(s)...
    auto at(Index index) const -> T const&;
    // _________________________
    // Assignment operator(s)...
    BasicArray<T>& operator=(BasicArray<T> const& array) = default;
    BasicArray<T>& operator=(AbstractArray<T> const& array);
    BasicArray<T>& operator=(std::initializer_list<T> values);

  protected:
    // _________________
    // Data getter(s)...
    std::vector<T> getData_();

  private:
    // ___________________
    // Helper method(s)...
    void swap_(BasicArray<T>& array);

    // _______
    // Data...
    std::vector<T> data_;

}; // BasicArray
}
} // blackbox



#endif

