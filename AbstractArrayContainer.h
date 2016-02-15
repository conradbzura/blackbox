#ifndef __ABSTRACTARRAYCONTAINER_H__
#define __ABSTRACTARRAYCONTAINER_H__

#include <memory>

#include "Cloneable.h"
#include "Index.h"
#include "Range.h"
#include "Subscript.h"

//template <typename T>
//using AbstractArrayContainerPtr = std::unique_ptr<AbstractArrayContainer<T>> ;

template <typename T>
class AbstractArrayContainer: public Cloneable<AbstractArrayContainer<T>> {
public:
	AbstractArrayContainer(); 
	AbstractArrayContainer(Subscript order);
	~AbstractArrayContainer();

	virtual std::auto_ptr<AbstractArrayContainer<T>> create(Subscript order) = 0;
	virtual auto at(Index index)-> std::shared_ptr<T>& = 0;
	
	virtual void duplicateTo(AbstractArrayContainer<T>& replica, Range range);
	virtual void translateTo(AbstractArrayContainer<T>& replica, Range range);
	virtual auto at(Subscript subscript)-> std::shared_ptr<T>&;
	virtual auto at(Subscript floor, Subscript ceiling)-> std::auto_ptr<AbstractArrayContainer<T>>;
	virtual auto at(Range range)-> std::auto_ptr<AbstractArrayContainer<T>>;
	virtual Integer getSize();
	virtual Subscript getOrder();

	// Cloneable override declarations
	void duplicateTo(AbstractArrayContainer<T>& replica);
	void translateTo(AbstractArrayContainer<T>& replica);

protected:
	Subscript order_;
};

#include "AbstractArrayContainer.cpp"

#endif
