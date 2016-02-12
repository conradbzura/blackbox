#include "Range.h"


Range::Range(): iterator_(this) {
	//noop
}

Range::Range(Subscript ceiling): ceiling_(ceiling), iterator_(this) {
	floor_.assign(ceiling.size(), 1);
}

Range::Range(Subscript floor, Subscript ceiling) : floor_(floor), ceiling_(ceiling), iterator_(this) {
	//noop
}

Range::~Range() {
	//noop
}

Subscript Range::getFloor() {
	return floor_;
}

Subscript Range::getCeiling() {
	return ceiling_;
}

Order Range::getOrder() {
	Order order;
	for (int i = 0; i < floor_.size(); i++) {
		order.push_back(ceiling_.at(i) - floor_.at(i) + 1);
	}
	return order;
}

Range::Iterator Range::getIterator(Subscript origin) {
	iterator_.setOrigin(origin);
	return iterator_;
}

Range::Iterator::Iterator() {
	//noop
}

Range::Iterator::Iterator(Range* range): range_(range) {
	//noop
}

Range::Iterator::operator Subscript() {
	return this_;
}

void Range::Iterator::setOrigin(Subscript origin) {
	this_ = origin;
}

void Range::Iterator::operator ++() {
	//todo
}

void Range::Iterator::operator --() {
	//todo
}

bool Range::Iterator::operator ==(Subscript subscript) {
	return false;
	//todo
}

bool Range::Iterator::operator !=(Subscript subscript) {
	return !(*this == subscript);
}
