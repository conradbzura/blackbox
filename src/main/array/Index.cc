#include "Index.h"

namespace blackbox {
namespace Arrays {

Index::Index()
{
    // noop
}

Index::Index(Integer index)
    : index_(index)
{
    // noop
}

Index::~Index()
{
    // noop
}

Index::operator Integer()
{
    return index_;
}

Subscript
Index::toSubscript(Subscript ceiling)
{
    std::vector<Integer> cumulativeProduct(ceiling.size(), 1);
    for (int i = 1; i < ceiling.size(); i++) {
        cumulativeProduct.at(i) =
            cumulativeProduct.at(i - 1) * ceiling.at(i - 1);
    }
    std::vector<Integer> subscript(ceiling.size(), 1);
    int j = ceiling.size() - 1;
    int index = index_ - 1;
    while (j >= 0) {
        subscript.at(j) += index / cumulativeProduct.at(j);
        index %= cumulativeProduct.at(j--);
    }
    return Subscript(subscript);
}
}
}
