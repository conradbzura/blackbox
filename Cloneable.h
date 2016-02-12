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

//begin: .cpp file
template <typename T>
Cloneable<T>::Cloneable() {
	//noop
}

template <typename T>
Cloneable<T>::~Cloneable() {
	//noop
}

template <typename T>
void Cloneable<T>::cloneTo(T& replica) {
	if (typeid(replica) == typeid(*this)) {
		duplicateTo(replica);
	}
	else {
		translateTo(replica);
	}
}
//end: .cpp file

//#include "Cloneable.cpp"

#endif
