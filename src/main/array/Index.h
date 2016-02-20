#ifndef __INDEX_H__
#define __INDEX_H__

#include "Subscript.h"

using Integer = int;

namespace blackbox {
	namespace array {
		class Index {
		public:
			Index();
			Index(Integer index);
			~Index();

			operator Integer();
			Subscript toSubscript(Subscript ceiling);
		private:
			Integer index_;
		};
	}
}

#endif
