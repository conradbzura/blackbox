#include "Index.h"

namespace blackbox {
	namespace array {

		Index::Index() {
			//noop
		}

		Index::Index(Integer index) : index_(index) {
			//noop
		}

		Index::~Index() {
			//noop
		}

		Index::operator Integer() {
			return index_;
		}

		Subscript Index::toSubscript(Subscript ceiling) {
			Subscript subscript, n;
			subscript.resize(ceiling.size());
			n.resize(ceiling.size());
			for (int i = 0; i < ceiling.size(); i++) {
				n.at(i) = 1;
				for (int j = ceiling.size() - 1; j > i; j++) {
					n.at(i) *= ceiling.at(j);
				}
			}
			for (int i = 0; i < ceiling.size(); i++) {
				subscript.at(i) = index_;
				for (int j = 0; j < i; j++) {
					subscript.at(i) = subscript.at(i) % n.at(j);
				}
			}
			return subscript;
		}
	}
}