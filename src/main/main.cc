

#include <vector>
#include <memory>

#include <typeinfo>
#include <iostream>

#include "main/context/Mode.h"

//#include "array/SimpleContainer.h"
//#include "array/AbstractContainer.h"
#include "main/array/Array/BasicArray.h"
#include "main/event/EventHandler/EventHandler.h"

void test5()
{

    using namespace blackbox;
    Arrays::Subscript sub({2, 2});
    Arrays::Index ind = sub.toIndex({3, 3});
    sub = ind.toSubscript({3, 3});

    for (int i = 1; i < 28; i++)
    {
        Arrays::Subscript ss = Arrays::Index(i).toSubscript({3, 3, 3});
    }

    WARNING("Warning occurred here");
    int three = 3;
    Arrays::BasicArray<int> a({three, 3});
    Arrays::BasicArray<int> A({3, 3});
    Arrays::BasicArray<int> subA({2, 2});
    a = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    A = {1, 2, 3, 4, 5, 6, 7, 8, 100};
    A = a;
    subA = {10, 20, 30, 40};
    //	std::auto_ptr<AbstractArray<int>> SUM(a + A);
    Arrays::AbstractArray<int> *b = new Arrays::BasicArray<int>({1, 3});
    Arrays::Subscript s({2, 2});
    Arrays::Subscript S({3, 3});
    Arrays::Index I = s.toIndex();
    // std::shared_ptr<int> i = a.at(4);
    int i = a.at(4);
    a.at(7) = 100;
    //*a.at(4) = 1;
    // std::shared_ptr<int> j = a.at(s);
    int *j = &a.at(s);
    int thirty = 30;
    //*j = thirty;
    // j.swap(std::make_shared<int>(30));
    Arrays::Range r(s);
    Arrays::Range R(s, S);
    a[r][r] = {13, 13, 13, 13};
    subA = a.at(r);
    a.at(r) = A[R];
    std::auto_ptr<Arrays::AbstractArray<int>> test; // =
    WARNING("Finished!");
}

void fake(int &i) {}

int main()
{
    // const std::auto_ptr<int> test = std::auto_ptr<int>();
    test5();
    // test3();
    /*
    Subscript s({ 1, 2, 3 });
    Order o({ 1, 2, 3 });
    test2(s);
    test2(o);
    */
    return 0;
}

/*


class AbstractOperatorStrategy {}

class SimpleOperatorStrategy : public AbstractOperatorStrategy {}

class Simple


*/
