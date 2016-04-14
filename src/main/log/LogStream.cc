#include "LogStream.h"

namespace blackbox {
	namespace Logs {
	//TODO split the implementation classes out into separate files

	const char* LogStream::File::CRLF = "\r\n";

	LogStream::File::File() : stream_(new std::ofstream) {
		//NOOP
	}

	LogStream::File::~File() {
		close();
	}

	void LogStream::File::open() {
		//TODO drop log file in application's root directory
		char* filename = ".log";
		stream_->open(filename, std::ios_base::binary | std::ios_base::out);
		if (!stream_->is_open()) {
			char errorMessage[256];
			snprintf(errorMessage, 256, "ERROR<%s:%d>: Could not open file <%s>!", __FILE__, __LINE__, filename);
			throw (std::runtime_error(errorMessage));
		}
	}

	void LogStream::File::close() {
		if (stream_) {
			stream_->close();
		}
	}

	void LogStream::File::write(const std::string& message) {
		*stream_ << message << CRLF;
		stream_->flush();
	}

	LogStream::Database::Database() {
		//TODO implement
	}

	LogStream::Database::~Database() {
		//TODO implement
	}

	void LogStream::Database::open() {
		//TODO implement
	}

	void LogStream::Database::close() {
		//TODO implement
	}

	void LogStream::Database::write(const std::string& message) {
		//TODO implement
	}

	LogStream::String::String() {
		//TODO implement
	}

	LogStream::String::~String() {
		//TODO implement
	}

	void LogStream::String::open() {
		//TODO implement
	}

	void LogStream::String::close() {
		//TODO implement
	}

	void LogStream::String::write(const std::string& message) {
		//TODO implement
	}
	}
}
