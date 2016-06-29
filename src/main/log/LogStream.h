#ifndef __STREAM_H__
#define __STREAM_H__

#include <fstream>
#include <memory>
#include <string>

#define LOG_FILE 'F'
#define LOG_DATABASE 'D'
#define LOG_STRING 'S'

namespace blackbox {
	namespace Log {
	class LogStream {
	public:
		virtual void open() = 0;
		virtual void close() = 0;
		virtual void write(const std::string& message) = 0;

		class Database;
		class File;
		class String;
	};

	class LogStream::File : public LogStream {
	public:
		File();
		~File();

		void open();
		void close();
		void write(const std::string& message);

	private:
		std::unique_ptr<std::ofstream> stream_;
		static const char* CRLF;
	};

	class LogStream::Database : public LogStream {
	public:
		Database();
		~Database();

		void open();
		void close();
		void write(const std::string& message);
	};

	class LogStream::String : public LogStream {
	public:
		String();
		~String();

		void open();
		void close();
		void write(const std::string& message);

	private:
		std::unique_ptr<std::ofstream> stream_;
	};
	}
}

#endif
