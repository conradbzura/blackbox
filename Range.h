#ifndef __RANGE_H__
#define __RANGE_H__

#include "Order.h"
#include "Subscript.h"

class Range {
public:
	class Iterator {
	public:
		Iterator();
		Iterator(Range* range);

		operator Subscript();
		void setOrigin(Subscript origin);
		void operator ++();
		void operator --();
		bool operator ==(Subscript subscript);
		bool operator !=(Subscript subscript);

	private:
		Range* range_;
		Subscript this_;
	};
	Range();
	Range(Subscript ceiling);
	Range(Subscript floor, Subscript ceiling);
	~Range();

	Subscript getFloor();
	Subscript getCeiling();
	Order getOrder();
	Iterator getIterator(Subscript origin);

private:
	Subscript floor_;
	Subscript ceiling_;
	Iterator iterator_;
};

#endif
