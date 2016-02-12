#ifndef __SUBSCRIPT_H__
#define __SUBSCRIPT_H__

#include <vector>

using Integer = int;

class Index;
class Subscript : public std::vector<Integer> {
public:
	Subscript();
	Subscript(std::vector<Integer> subscript);
	~Subscript();

	Index toIndex(Subscript ceiling);
};

#endif
