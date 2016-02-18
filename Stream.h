#ifndef __STREAM_H__
#define __STREAM_H__

#include <fstream>
#include <memory>

namespace log {

#define LOG_FILE 'F'
#define LOG_DATABASE 'D'
#define LOG_STRING 'S'

class Stream {
public:
	Stream();
	~Stream();

	virtual void write() = 0;
	virtual void open();
	virtual void close();
};

class File : public Stream {
public:
	File();
	~File();

	void write();
	void open();
	void close();

private:
	std::unique_ptr<std::ofstream> stream_;
};

class Database : public Stream {
public:
	Database();
	~Database();

	void write();
	void open();
	void close();
};

class String : public Stream {
public:
	String();
	~String();

	void write();
	void open();
	void close();

private:
	std::unique_ptr<std::ofstream> stream_;
};

}

#endif
