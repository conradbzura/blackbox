#ifndef __SUBSCRIPT_H__
#define __SUBSCRIPT_H__

#include <vector>

using Integer = int;

namespace blackbox {
	namespace Arrays {
	class Index;
	class Subscript : public std::vector<Integer> {
	public:
		Subscript();
		//Subscript(std::vector<Integer> subscript);
		Subscript(std::vector<Integer> subscript);
		Subscript(std::initializer_list<Integer> subscript);
		~Subscript();

		Index toIndex() const;
		Index toIndex(Subscript ceiling) const;
	};
}
}
#endif
