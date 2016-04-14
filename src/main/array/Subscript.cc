#include "Subscript.h"
#include "Index.h"

namespace blackbox {
	namespace Arrays {

	Subscript::Subscript() {
		//noop
	}

	Subscript::Subscript(std::vector<Integer> subscript) : std::vector<Integer>(subscript) {
		//noop
	}

	Subscript::Subscript(std::initializer_list<Integer> subscript) : std::vector<Integer>(subscript) {
		//noop
	}

	Subscript::~Subscript() {
		//noop
	}

	Index Subscript::toIndex() const {
		return this->toIndex(*this);
	}

	Index Subscript::toIndex(Subscript ceiling) const {
		Integer index = 1;
		int n = 1;
		for (int i = 0; i < ceiling.size(); i++) {
			index += (this->at(i) - 1) * n;
			n *= ceiling.at(i);
		}
		return Index(index);
	}
}
}
