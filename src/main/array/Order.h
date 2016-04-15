#ifndef __ORDER_H__
#define __ORDER_H__

#include "Subscript.h"

namespace blackbox
{
namespace Arrays
{
class Order : public Subscript
{
  public:
    Order();
    ~Order();

    operator Subscript();
    Index toIndex() const;
};
}
}

#endif
