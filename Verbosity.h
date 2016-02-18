#ifndef __VERBOSITY_H__
#define __VERBOSITY_H__

#include <string>

class Verbosity {
protected:
	Verbosity() {}
};

class Error: public Verbosity {
	operator std::string() {
		return "ERROR";
	}
};

class Warning : public Verbosity {
	operator std::string() {
		return "WARNING";
	}
};

class Info : public Verbosity {
	operator std::string() {
		return "INFO";
	}
};

class Debug : public Verbosity {
	operator std::string() {
		return "DEBUG";
	}
};

#endif
