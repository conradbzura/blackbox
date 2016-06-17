#ifndef __RANGE_H__
#define __RANGE_H__

#include "Index.h"
#include "Order.h"
#include "Subscript.h"

namespace blackbox {
namespace Arrays {
class Range
{
  public:
    class Iterator
    {
      public:
        Iterator();
        Iterator(Range* range);

        operator Subscript();

        void operator++();
        void operator++(int);
        void operator--();
        void operator--(int);
        bool operator==(Subscript subscript);
        bool operator!=(Subscript subscript);
        bool operator<=(Subscript subscript);
        bool operator>=(Subscript subscript);
        bool operator<(Subscript subscript);
        bool operator>(Subscript subscript);

        void setOrigin(Subscript origin);

      private:
        void increment(int i = 0);
        void decrement(int i = 0);

        Range* range_;
        Subscript this_;
    };
    Range();
    Range(Subscript ceiling);
    Range(Subscript floor, Subscript ceiling);
    ~Range();

    Subscript getFloor();
    Subscript getCeiling();
    Subscript map(Subscript subscript);
    Subscript map(Subscript subscript) const;
    Order getOrder();
    Iterator getIterator();
    Iterator getIterator(Subscript origin);

  private:
    Subscript floor_;
    Subscript ceiling_;
    Iterator iterator_;
};
}
}

#endif
