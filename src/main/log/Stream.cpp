#include "Stream.h"

namespace blackbox {
	namespace log {
		//todo: split the implementation classes out into separate files

		const char* File::CRLF = "\r\n";

		File::File() : stream_(new std::ofstream) {
			//noop
		}

		File::~File() {
			close();
		}

		void File::open() {
			//todo: drop log file in application's root directory
			char* filename = ".log";
			stream_->open(filename, std::ios_base::binary | std::ios_base::out);
			if (!stream_->is_open()) {
				char errorMessage[256];
				snprintf(errorMessage, 256, "ERROR<%s:%d>: Could not open file <%s>!", __FILE__, __LINE__, filename);
				throw (std::runtime_error(errorMessage));
			}
		}

		void File::close() {
			if (stream_) {
				stream_->close();
			}
		}

		void File::write(const std::string& message) {
			(*stream_) << message << CRLF;
		}

		Database::Database() {
			//todo: implement
		}

		Database::~Database() {
			//todo: implement
		}

		void Database::open() {
			//todo: implement
		}

		void Database::close() {
			//todo: implement
		}

		void Database::write(const std::string& message) {
			//todo: implement
		}

		String::String() {
			//todo: implement
		}

		String::~String() {
			//todo: implement
		}

		void String::open() {
			//todo: implement
		}

		void String::close() {
			//todo: implement
		}

		void String::write(const std::string& message) {
			//todo: implement
		}

	} // log
} // blackbox