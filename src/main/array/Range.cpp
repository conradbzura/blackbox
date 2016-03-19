#include "Range.h"

namespace blackbox {

	Range::Range() : iterator_(this) {
		//noop
	}

	Range::Range(Subscript ceiling) : ceiling_(ceiling), iterator_(this) {
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

	Subscript Range::map(Subscript subscript) {
		return const_cast<const Range*>(this)->map(subscript);
	}

	Subscript Range::map(Subscript subscript) const {
		if (floor_ == std::vector<Integer>(floor_.size(), 1))
		{
			return subscript;
		}
		else
		{
			for (int i = 0; i < floor_.size(); i++)
			{
				subscript.at(i) += floor_.at(i) - 1;
			}
			return subscript;
		}
	}

	Order Range::getOrder() {
		Order order;
		for (int i = 0; i < floor_.size(); i++) {
			order.push_back(ceiling_.at(i) - floor_.at(i) + 1);
		}
		return order;
	}

	Range::Iterator Range::getIterator() {
		iterator_.setOrigin(this->getFloor());
		return iterator_;
	}

	Range::Iterator Range::getIterator(Subscript origin) {
		iterator_.setOrigin(origin);
		return iterator_;
	}

	Range::Iterator::Iterator() {
		//noop
	}

	Range::Iterator::Iterator(Range* range) : range_(range) {
		//noop
	}

	Range::Iterator::operator Subscript() {
		return this_;
	}

	void Range::Iterator::operator ++() {
		increment();
	}

	void Range::Iterator::operator ++(int) {
		increment();
	}

	void Range::Iterator::operator --() {
		decrement();
	}

	void Range::Iterator::operator --(int) {
		decrement();
	}

	bool Range::Iterator::operator ==(Subscript subscript) {
		return this_ == subscript;
	}

	bool Range::Iterator::operator !=(Subscript subscript) {
		return this_ != subscript;
	}

	bool Range::Iterator::operator <=(Subscript subscript) {
		return this_ <= subscript;
	}

	bool Range::Iterator::operator >=(Subscript subscript) {
		return this_ >= subscript;
	}

	bool Range::Iterator::operator <(Subscript subscript) {
		return this_ < subscript;
	}

	bool Range::Iterator::operator >(Subscript subscript) {
		return this_ > subscript;
	}

	void Range::Iterator::setOrigin(Subscript origin) {
		this_ = origin;
	}

	void Range::Iterator::increment(int i) {
		if (this_ >= range_->ceiling_) {
			this_.front() = range_->ceiling_.front() + 1;
			return;
		}
		if (i == this_.size()) {
			i = 0;
		}
		if (this_.at(i) < range_->ceiling_.at(i)) {
			this_.at(i)++;
		}
		else {
			this_.at(i) = range_->floor_.at(i);
			increment(++i);
		}
	}

	void Range::Iterator::decrement(int i) {
		if (this_ <= range_->floor_) {
			this_.front() = range_->floor_.front() - 1;
			return;
		}
		if (i == this_.size()) {
			i = 0;
		}
		if (this_.at(i) > range_->floor_.at(i)) {
			this_.at(i)--;
		}
		else {
			this_.at(i) = range_->ceiling_.at(i);
			increment(++i);
		}
	}
}
