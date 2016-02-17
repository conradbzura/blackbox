#ifndef __LOGSTREAM_H__
#define __LOGSTREAM_H__

#include <fstream>
#include <memory>

class LogStream {
public:
	LogStream();
	~LogStream();

	void write();
	void openStream();
	void closeStream();

private:
	std::unique_ptr<std::ofstream> stream_;

};

#endif
