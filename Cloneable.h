#ifndef __CLONEABLE_H__
#define __CLONEABLE_H__



template <typename T>
class Cloneable {
public:
	Cloneable();
	~Cloneable();

	virtual void cloneTo(T& replica);
	virtual void duplicateTo(T& replica) = 0;
	virtual void translateTo(T& replica) = 0;
};

#include "Cloneable.cpp"

#endif
