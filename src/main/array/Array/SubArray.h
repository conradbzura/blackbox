#ifndef __SUBARRAY_H__
#define __SUBARRAY_H__

#include "main/array/Array/AbstractArray.h"

namespace blackbox {
namespace Arrays {
// SubArray
// _______________________________________________________________________
// Provides a handle to an AbstractArray object with a specific range.
// Cannot be instantiated directly - a SubArray object is returned from an
// AbstractArray object using the at(Range) accessor method.
template <typename T>
class AbstractArray<T>::SubArray : public virtual AbstractArray<T>
{
    SubArray() = delete;

  public:
    // Constructor(s)...
    SubArray(SubArray&& array) {}
    SubArray(SubArray const& array) {}
    SubArray(AbstractArray<T>* const array, Range range);
    SubArray(const AbstractArray<T>* const array, Range range);
    virtual ~SubArray() = default;
    
    // Accessor method(s)...
    auto at(Index index) -> T&;
    auto at(Subscript subscript) -> T&;
    auto at(Range range) -> SubArray;
    
    // Const accessor method(s)...
    auto at(Index index) const -> T const&;
    auto at(Subscript subscript) const -> T const&;
    auto at(Range range) const -> const SubArray;
    
    // Assignment operator(s)...
    SubArray& operator=(SubArray const& array);
    SubArray& operator=(AbstractArray<T> const& array);
    SubArray& operator=(std::initializer_list<T> values);

  protected:
    // Meta-data getter(s)...
    auto getParent_() -> AbstractArray<T>* const;
    auto getParent_() const -> const AbstractArray<T>* const;
    Range getRange_() const;

  private:
    // Helper method(s)...
    SubArray& copy_(AbstractArray<T> const& array);

    // Meta-data...
    union
    {
        AbstractArray<T>* const parent_;
        const AbstractArray<T>* const constParent_;
    };
    Range range_;

}; // SubArray
}
} // blackbox



#endif
